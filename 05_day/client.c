#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd;
	int ret;
	fd = open("myfifo", O_RDWR);
	getchar();
	ret = write(fd, "l", 1);   // "l"
	getchar();
	ret = write(fd, "s", 1);   // "s"
	getchar();
	ret = write(fd, "\n", 1);   // "\n"
	close(fd);
	return 0;
}








