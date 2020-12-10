#if 1
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int count=0; 
int mutex = 0;

typedef int int32_t;

int __bionic_cmpxchg(int32_t old_value, int32_t new_value, volatile int32_t* ptr)
{
    int32_t prev;
    __asm__ __volatile__ ("lock; cmpxchgl %1, %2"
                          : "=a" (prev)
                          : "q" (new_value), "m" (*ptr), "0" (old_value)
                          : "memory");
    return prev != old_value;
}

void spin_lock( int *lock )
{
	while( __bionic_cmpxchg(0, 1, lock) );
}

void spin_unlock( int *lock )
{
	*lock = 0;
}

void *handler_1( void *data)
{
	int i;
	for( i=0; i<10000000; i++ )
	{
		my_lock(&mutex);
		count++;
		my_unlock(&mutex);
	}
	return 0;
}
void *handler_2( void *data)
{
	int i;
	for( i=0; i<10000000; i++ )
	{
		my_lock(&mutex);
		count++;
		my_unlock(&mutex);
	}
	return 0;
}

int main()
{
	int ret;
	pthread_t thread[2];

	pthread_create(&thread[0], 0, handler_1, 0);
	pthread_create(&thread[1], 0, handler_2, 0);
	pthread_join(thread[0], 0 );
	pthread_join(thread[1], 0 );
	printf("count=%d\n", count);
		
	return 0;
}
#endif

