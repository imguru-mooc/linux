#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void foo(int *count)
{
	printf("foo(), count=%d\n", ++*count );
}

void *handler_1(void *data)
{
	int count = 0;
	foo(&count);
	foo(&count);
	return 0;
}

void *handler_2(void *data)
{
	int count = 0;
	foo(&count);
	foo(&count);
	foo(&count);
	return 0;
}
int main()
{
	pthread_t thread[2];
	pthread_create(&thread[0], 0, handler_1, 0 );
	pthread_create(&thread[1], 0, handler_2, 0 );
	pthread_join(thread[0], 0 );
	pthread_join(thread[1], 0 );
	return 0;
}
