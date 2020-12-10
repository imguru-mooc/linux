#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_mutexattr_t attr;

int foo(int i)
{
	int ret;
	if(i==1)
		return 1;
	pthread_mutex_lock( &mutex );
	printf("임계영역 진입\n");
	ret = i*foo(i-1);
	pthread_mutex_unlock( &mutex );
	return ret;
}

int main()
{
	pthread_mutexattr_init( &attr );
	pthread_mutexattr_settype( &attr , PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init( &mutex , &attr );
	int ret;
	ret = foo(5);  // 5*4*3*2*1
	printf("ret=%d\n", ret );
	return 0;
}
