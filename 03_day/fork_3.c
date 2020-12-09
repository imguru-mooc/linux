#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	pid = fork();

	if( pid > 0 )
		printf("parent : after\n");
	else if ( pid == 0 )
		printf("child  : after\n");
	return 0;
}
