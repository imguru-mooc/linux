#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int mutex = 1;

void * foo(void *data)
{
	syscall(SYS_futex, &mutex, 0, 1, 0); // __futex_wait();
	printf("임계영역 진입\n");
	return 0;
}
int main()
{
	pthread_t thread;
	pthread_create( &thread, 0, foo, 0 );
	getchar();
	syscall(SYS_futex, &mutex, 1, 1); // __futex_wake();
	pthread_join( thread, 0 );
	return 0;
}
