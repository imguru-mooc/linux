#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

ssize_t readline(int fd, void *vptr, size_t maxlen)
{
	int n, rc;
	char c, *ptr;
	ptr = vptr;
	for (n = 1; n < maxlen; n++) 
	{
		if ( (rc = read(fd, &c, 1)) == 1) {
			*ptr++ = c;
			if (c == '\n')
				break; /* newline is stored, like fgets() */
		} else if (rc == 0) {
			if (n == 1)
				return(0); /* EOF, no data read */
			else
				break; /* EOF, some data was read */
		} else
			return (-1); /* error, errno set by read() */
	}
	*ptr = 0; /* null terminate like fgets() */
	return(n);
}

int main()
{
	char buff[512];
	int fd;
	int ret;
	fd = open("myfifo", O_RDWR);
	ret = readline(fd, buff, sizeof buff);   // "ls\n"
	buff[ret-1] = 0;  // "ls"
	system(buff);
	close(fd);
	return 0;
}








