#if 1
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int i;
	int fd[2];
	char buff[128];
	int ret;
	pipe(fd);

	for( i=0; ;i++)
	{
		write( fd[1], "a", 1);
		printf("%d\n", i );
	}
	return 0;
}
#endif
#if 0
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

	write( fd[1], "he", 2);
	write( fd[1], "ll", 2);
	write( fd[1], "o", 1);

	while( ret = read(fd[0], buff, sizeof buff ) )
	{
		sleep(1);
		write( 1, buff, ret);
	}
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int fd[2];
	char ch;
	pipe(fd);

	write( fd[1], "hello", 5);

	while( read(fd[0], &ch, 1))
	{
		sleep(1);
		write( 1, &ch, 1);
	}
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd[2];
	pipe(fd);
	printf("fd[0]=%d\n", fd[0]);
	printf("fd[1]=%d\n", fd[1]);
	return 0;
}
#endif
