#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int global=6;

int main()
{
	pid_t pid;
	pid = fork();

	if( pid > 0 )
	{
		sleep(1);
		printf("parent : global=%d\n", global);
	}
	else if ( pid == 0 )
		printf("child  : global=%d\n", ++global);
	return 0;
}
