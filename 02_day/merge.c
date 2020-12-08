#if 1
#include <stdio.h>
#include <string.h>

// ./a.out    src1     src2   ...  target
//  argv[0]  argv[1]  argv[2]      argv[argc-1]

typedef struct
{
	char fname[20];
	int  fsize;
} INFO;

int get_fsize(FILE *fp)
{
	size_t size, offset;
	offset = ftell(fp);
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, offset, SEEK_SET);

	return size;
}

int main( int argc, char **argv )
{
	FILE *src;
	FILE *dst;
	char buff[512];
	int ret;
	int i;
	INFO info;

	dst = fopen( argv[argc-1], "w" );

	for(i=0; i<argc-2; i++)
	{
		src = fopen( argv[i+1], "r" );

		strcpy( info.fname, argv[i+1] );
		info.fsize = get_fsize(src);

		fwrite( &info, sizeof info, 1, dst );

		while( ret = fread( buff, 1, sizeof buff, src ))
			fwrite( buff, 1, ret, dst );

		fclose(src);
	}

	fclose(dst);
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
