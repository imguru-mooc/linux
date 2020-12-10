#if 1
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int global=6;
int main()
{
	pid_t pid;
	pid = fork();
	if( pid == 0 )
	{
		printf("child : global=%d\n", ++global);
		exit(0);
	}
	wait(0);
	printf("parent: global=%d\n", global);
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	pid = fork();
	if( pid == 0 )
	{
		printf("child\n");
		exit(0);
	}
	wait(0);
	printf("parent\n");
	return 0;
}
#endif
