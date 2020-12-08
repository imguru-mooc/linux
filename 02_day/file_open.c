#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// ./a.out    aaa     
//  argv[0]  argv[1]  

int main( int argc, char **argv )
{
	int fd1;
	int fd2;
	char buff[512];
	int ret;

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[1], O_RDONLY);

	ret = read(fd1, buff, 2);
	write( 1, buff,  ret);

	ret = read(fd2, buff, 2);
	write( 1, buff,  ret);

	close(fd1);
	close(fd2);
	return 0;
}
