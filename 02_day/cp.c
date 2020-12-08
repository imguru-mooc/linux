#include <stdio.h>

// ./a.out    aaa     bbb
//  argv[0]  argv[1]  argv[2]

int main( int argc, char **argv )
{
	FILE *src;
	FILE *dst;
	char buff[512];
	int ret;

	src = fopen( argv[1], "r" );
	dst = fopen( argv[2], "w" );

	while( ret = fread( buff, 1, sizeof buff, src ))
		fwrite( buff, 1, ret, dst );

	fclose(src);
	fclose(dst);
	return 0;
}
