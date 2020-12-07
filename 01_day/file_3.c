#if 0
#include <stdio.h>

int main( int argc, char **argv)
{
	int ch;  // 00000000 00000000 00000000 11111111
	ch = 0xff;

	printf("%d\n", ch );
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main( int argc, char **argv)
{
	char ch;
	ch = 0xff;

	printf("%d\n", ch );
	return 0;
}
#endif
#if 1
#include <stdio.h>

// ./a.out file_1.c
// argv[0] argv[1]
int main( int argc, char **argv)
{
	FILE *fp;
	int ch;
	int count=0;
	fp = fopen(argv[1], "r");

	while ( (ch = fgetc( fp )) != EOF )
		count++;

	printf( "count=%d\n", count);
	fclose(fp);
	return 0;
}
#endif
