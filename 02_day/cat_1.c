#include <stdio.h>

// ./a.out    aaa     
//  argv[0]  argv[1]  

int main( int argc, char **argv )
{
	FILE *src
	char buff[512];
	int ret;

	src = fopen( argv[1], "r" );

	while( ret = fread( buff, 1, sizeof buff, src ))
		fwrite( buff, 1, ret, stdout );

	fclose(src);
	return 0;
}
