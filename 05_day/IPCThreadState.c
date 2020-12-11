#include <pthread.h>
#include <stdio.h>

static bool gHaveTLS = false;
static pthread_key_t gTLS = 0;

class IPCThreadState
{
	private:
		IPCThreadState()
		{
			pthread_setspecific(gTLS, this);
			printf("IPCThreadState::IPCThreadState()\n");
		}
	public:
		static void threadDestructor(void *st)
		{
			IPCThreadState* const self = static_cast<IPCThreadState*>(st);
			delete self;
		}

		static IPCThreadState* self()
		{
			if (gHaveTLS) {
restart:
				const pthread_key_t k = gTLS;
				IPCThreadState* st = (IPCThreadState*)pthread_getspecific(k);
				if (st) return st;
				return new IPCThreadState;
			}

			if (!gHaveTLS) {
				if (pthread_key_create(&gTLS, threadDestructor) != 0) {
					return NULL;
				}
				gHaveTLS = true;
			}
			goto restart;
		}
};

void * handler_1( void *data )
{
	printf("handler_1()\n");
	IPCThreadState* t1 = IPCThreadState::self();
	IPCThreadState* t2 = IPCThreadState::self();
	return 0;
}

void * handler_2( void *data )
{
	printf("handler_2()\n");
	IPCThreadState* t1 = IPCThreadState::self();
	IPCThreadState* t2 = IPCThreadState::self();
	return 0;
}

int main()
{
	pthread_t thread[2];
	pthread_create( &thread[0], 0, handler_1, 0 );
	pthread_create( &thread[1], 0, handler_2, 0 );
	pthread_join( thread[0], 0);
	pthread_join( thread[1], 0);
	return 0;
}
