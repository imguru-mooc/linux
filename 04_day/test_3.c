#if 1
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int count=0; 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handler_1( void *data)
{
	int i;
	for( i=0; i<1000000000; i++ )
	{
		pthread_mutex_lock(&mutex);
		count++;
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}
void *handler_2( void *data)
{
	int i;
	for( i=0; i<1000000000; i++ )
	{
		pthread_mutex_lock(&mutex);
		count++;
		pthread_mutex_unlock(&mutex);
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

