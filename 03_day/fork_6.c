#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	int i;
	pid = fork();

	if( pid == 0 )
	{
		for(i=0; i<3; i++ )
		{
			sleep(1);
			printf("\t\t\tchild\n");
		}
		exit(7);
	}

	wait(0);
	while(1)
	{
		sleep(1);
		printf("parent\n");
	}
	return 0;
}






