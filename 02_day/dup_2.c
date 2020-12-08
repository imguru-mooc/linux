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

	if( argc > 1 )
	{
    	src = open(argv[1], O_RDONLY);
		close(0);
		dup(src);
	}

	while( ret = read(0, buff, sizeof buff))
		write( 1, buff,  ret);

	if( argc > 1 )
		close(src);
	return 0;
}
