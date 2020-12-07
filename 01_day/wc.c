#if 1
#include <stdio.h>

// 13 167 a.txt
// ./a.out a.txt
// argv[0] argv[1]
int main( int argc, char **argv)
{
	FILE *fp;
	int ch;
	int flag=0;
	int line_cnt=0;
	int word_cnt=0;
	int char_cnt=0;

	fp = fopen(argv[1], "r");

	while ( (ch = fgetc( fp )) != EOF )
	{
		if( ch == '\n' || ch == ' ' || ch == '\t' )
		{
			flag = 0;
		}
		else
		{
			if( flag == 0 )
			{
				word_cnt++;
				flag = 1;
			}
		}

		if( ch == '\n' )
			line_cnt++;
		char_cnt++;
	}

	printf( "%d %d %d %s\n", line_cnt, word_cnt, char_cnt, argv[1]);
	fclose(fp);
	return 0;
}
#endif
