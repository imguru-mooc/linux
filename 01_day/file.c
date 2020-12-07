#include <stdio.h>

int main()
{
	FILE *fp;
	int ch;

	fp = fopen("file.c", "r" );
	while( (ch = fgetc(fp) ) != EOF )
		printf("%d\n", ch);

	fclose(fp);
	return 0;
}
