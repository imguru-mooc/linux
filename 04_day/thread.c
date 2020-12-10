
#if 1
#include <pthread.h>
#include <stdio.h>

void *foo( void *data)
{
	printf("child : local=%d\n", ++*(int*)data);
	return 0;
}

int main()
{
	int local=10;
	pthread_t thread;

	//foo(&local);
	pthread_create(&thread, 0, foo, &local);
	pthread_join(thread, 0 );
	printf("parent: local=%d\n", local);
	return 0;
}
#endif

#if 0
#include <pthread.h>
#include <stdio.h>

int global=6;

void *foo( void *data)
{
	printf("child : global=%d\n", ++global);
	return 0;
}

int main()
{
	pthread_t thread;

	pthread_create(&thread, 0, foo, 0);
	pthread_join(thread, 0 );
	printf("parent: global=%d\n", global);
	return 0;
}
#endif
#if 0
#include <pthread.h>
#include <stdio.h>

void *foo( void *data)
{
	printf("child\n");
	return 0;
}

int main()
{
	pthread_t thread;

	pthread_create(&thread, 0, foo, 0);
	pthread_join(thread, 0 );
	printf("parent\n");
	return 0;
}
#endif
