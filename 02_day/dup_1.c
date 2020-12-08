#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main( int argc, char **argv )
{
	int fd;
	char buff[512];
	int ret;

    fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT , 0666);

	close(1);
	dup(fd);

	printf("hello\n");  // write(1, "hello\n", 6);
	close(fd);
	return 0;
}
