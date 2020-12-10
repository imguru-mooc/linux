#include <pthread.h>
#include <stdio.h>

pthread_key_t key[2];

void my_destructor(void* data)
{
	printf("my_destructor()\n");
}

int main()
{
    pthread_key_create(&key[0], my_destructor);
    pthread_key_create(&key[1], my_destructor);
	printf("key[0]=%d\n", key[0] );
	printf("key[1]=%d\n", key[1] );
	return 0;
}
