#if 1
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define err_quit(msg) do {    \
	fprintf(stderr, "%s at %s : %d : %s \n",                   \
			msg, __FILE__, __LINE__, strerror(errno));                 \
	exit(0);               \
} while(0)

int main()
{
	int fd;
	int ret;
	char buff[512];
	fd = open("xxx", O_RDONLY );

	if( fd < 0 )
		err_quit("open()");
	else
    	printf("something\n");


	ret = read( fd, buff, sizeof buff );
	write( 1, buff, ret );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define err_quit(msg) do {    \
	perror(msg);           \
	exit(0);               \
} while(0)

int main()
{
	int fd;
	int ret;
	char buff[512];
	fd = open("xxx", O_RDONLY );

	if( fd < 0 )
		err_quit("open()");
	else
    	printf("something\n");


	ret = read( fd, buff, sizeof buff );
	write( 1, buff, ret );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define err_quit(msg) {    \
	perror(msg);           \
	exit(0);               \
}

int main()
{
	int fd;
	int ret;
	char buff[512];
	fd = open("xxx", O_RDONLY );

	if( fd < 0 )
		err_quit("open()");
	else
    	printf("something\n");


	ret = read( fd, buff, sizeof buff );
	write( 1, buff, ret );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void err_quit( char *msg )
{
	perror(msg);
	exit(0);
}

int Open(const char *pathname, int flags)
{
	int fd;
	fd = open(pathname, flags);
	if( fd < 0 )
		err_quit("open()");
	return fd;
}

int main()
{
	int fd;
	int ret;
	char buff[512];
	fd = Open("xxx", O_RDONLY );

	ret = read( fd, buff, sizeof buff );
	write( 1, buff, ret );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void err_quit( char *msg )
{
	perror(msg);
	exit(0);
}

int main()
{
	int fd;
	int ret;
	char buff[512];
	fd = open("xxx", O_RDONLY );

	if( fd < 0 )
		err_quit("open()");

	ret = read( fd, buff, sizeof buff );
	write( 1, buff, ret );
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd;
	int ret;
	char buff[512];
	fd = open("xxx", O_RDONLY );

	if( fd < 0 )
	{
		perror("open()");
		exit(0);
	}
	ret = read( fd, buff, sizeof buff );
	write( 1, buff, ret );
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main()
{
	int fd;
	fd = open("xxx", O_RDONLY );

	if( fd < 0 )
	{
		//printf("errno=%d\n", errno );
		//printf("open(), strerror=%s\n", strerror(errno) );
		perror("open()");
	}
	return 0;
}
#endif
