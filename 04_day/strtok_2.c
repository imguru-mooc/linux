#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *handler_1(void *data)
{
	char ip[] = ".....192......168.....56.....101....";
	char *p;

	p = strtok(ip, ".");
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok(0, ".");
		sleep(1);
	}
	return 0;
}

void *handler_2(void *data)
{
	char hp[] = "010-1234-5678";
	char *p;

	p = strtok(hp, "-");
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok(0, "-");
		sleep(1);
	}
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
