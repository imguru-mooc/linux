#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd;
	int ret;
	char buff[512];

	fd = open("xxx", O_RDONLY );

	ret = read( fd, buff, 2 );
	write(1, buff, ret );

	if(fork()==0)
	{
		ret = read( fd, buff, 2 );
		write(1, buff, ret );
	}

	return 0;
}
