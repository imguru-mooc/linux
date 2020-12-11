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
		write( fd[1], "he", 2);
		write( fd[1], "ll", 2);
		write( fd[1], "o", 1);
		close(fd[1]);
		exit(0);
	}

	close(fd[1]);
	while( ret = read(fd[0], buff, sizeof buff ) )
	{
		sleep(1);
		write( 1, buff, ret);
	}
	close(fd[0]);
	return 0;
}
#endif
