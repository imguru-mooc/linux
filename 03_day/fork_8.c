#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void my_sig(int signo)
{
	printf("my_sig(%d)\n", signo );
	wait(0);
}

int main()
{
	pid_t pid;
	int i, j;

	signal( SIGCHLD, my_sig );

	for(i=0; i<50; i++ )
	{
		pid = fork();
		if( pid == 0 )
		{
			for(j=0; j<3; j++ )
			{
				sleep(1);
				printf("\t\t\tchild\n");
			}
			exit(7);
		}
	}

	while(1)
	{
		sleep(1);
		printf("parent\n");
	}
	return 0;
}





