#if 1
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int fd[2];
	char buff[128];
	int ret;
	pipe(fd);

	if(fork()==0)
	{
		close(fd[0]);
		close(1);
		dup(fd[1]);
		execlp("ls","ls",(char*)0);
	}
	close(fd[1]);
	close(0);
	dup(fd[0]);
	execlp("wc","wc",(char*)0);

	return 0;
}
#endif
