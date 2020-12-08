#if 1
#include <stdio.h>
#include <string.h>

// ./a.out    src     
//  argv[0]  argv[1]  

typedef struct
{
	char fname[20];
	int  fsize;
} INFO;

int main( int argc, char **argv )
{
	FILE *src;
	FILE *dst;
	char buff[2];
	int ret;
	int i;
	int len;
	INFO info;

	src = fopen( argv[1], "r" );  // ccc

	while( fread( &info, sizeof info, 1, src ))
	{
		printf("fname=%s\n", info.fname );
		printf("fsize=%d\n", info.fsize );

		dst = fopen( info.fname, "w" );

		while( info.fsize > 0 )
		{
			if( info.fsize > sizeof(buff) )
				len  = sizeof(buff);
			else
				len = info.fsize;
			ret = fread( buff, 1, len, src );
			fwrite( buff, 1, ret, dst );
			printf( "fwrite( buff, 1, %d, dst )\n", ret );
			info.fsize -= ret ;
			printf( "info.size=%d\n", info.fsize);
		}

		fclose(dst);
	}

	fclose(src);
	return 0;
}
#endif
#if 0
#include <stdio.h>

// ./a.out    src1     src2   ...  target
//  argv[0]  argv[1]  argv[2]      argv[argc-1]

int main( int argc, char **argv )
{
	FILE *src;
	FILE *dst;
	char buff[512];
	int ret;
	int i;

	dst = fopen( argv[argc-1], "w" );

	for(i=0; i<argc-2; i++)
	{
		src = fopen( argv[i+1], "r" );

		while( ret = fread( buff, 1, sizeof buff, src ))
			fwrite( buff, 1, ret, dst );

		fclose(src);
	}

	fclose(dst);
	return 0;
}
#endif
