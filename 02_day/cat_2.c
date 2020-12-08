#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// ./a.out    aaa     
//  argv[0]  argv[1]  

int main( int argc, char **argv )
{
	int src;
	char buff[512];
	int ret;

    src = open(argv[1], O_RDONLY);

	while( ret = read(src, buff, sizeof buff))
		write( 1, buff,  ret);

	close(src);
	return 0;
}
