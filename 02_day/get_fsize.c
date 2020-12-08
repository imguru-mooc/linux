#include <stdio.h>
#include <string.h>

int get_fsize(FILE *fp)
{
	size_t size, offset;
	offset = ftell(fp);
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, offset, SEEK_SET);

	return size;
}

int main( int argc, char **argv)
{
	FILE *fp;
	size_t size;
	int ch;
	fp = fopen(argv[1], "r");

	ch = fgetc(fp);
	printf("ch=%c\n", ch );

	size = get_fsize(fp);
	printf("size=%ld\n", size );

	ch = fgetc(fp);
	printf("ch=%c\n", ch );
	fclose(fp);
	return 0;
}
