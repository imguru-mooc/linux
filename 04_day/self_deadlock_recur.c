#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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
	int ret;
	ret = foo(5);  // 5*4*3*2*1
	printf("ret=%d\n", ret );
	return 0;
}
