#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_key_t key=0x1111;

void my_destructor(void* data)
{
	printf("data=%p\n", data );
    printf("my_destructor()\n");
	free(data);
}

void foo(void)
{
	int *count;
	count = pthread_getspecific( key );
	if( count == 0 ) 
	{
		count = calloc( 1, sizeof(int) );
		printf("count=%p\n", count );
		pthread_setspecific( key, count );
	}
	printf("foo(), count=%d\n", ++*count );
}
//----------------------------------------------------

void *handler_1(void *data)
{
	foo();
	foo();
	return 0;
}

void *handler_2(void *data)
{
	foo();
	foo();
	foo();
	return 0;
}

int main()
{
	pthread_t thread[2];
    pthread_key_create(&key, my_destructor);
	pthread_create(&thread[0], 0, handler_1, 0 );
	pthread_create(&thread[1], 0, handler_2, 0 );
	pthread_join(thread[0], 0 );
	pthread_join(thread[1], 0 );
	return 0;
}
