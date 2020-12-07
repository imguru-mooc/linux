#if 1
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	fprintf(stderr, "hello");
	sleep(3);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("hello");
	sleep(3);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <unistd.h>

// ./a.out file_1.c
// argv[0] argv[1]
int main( int argc, char **argv)
{
	FILE *fp;
	char buff[512];
	size_t ret;
	fp = fopen(argv[1], "r");

	while ( ret = fread(buff, 1, sizeof(buff), fp) )
	{
		fwrite(buff, 1, ret, stdout);
		usleep(100000);
	}

	fclose(fp);
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <unistd.h>

// ./a.out file_1.c
// argv[0] argv[1]
int main( int argc, char **argv)
{
	FILE *fp;
	char buff[1024];
	int ret;
	fp = fopen(argv[1], "r");

	while ( fgets(buff, sizeof(buff), fp) )
	{
		fputs(buff, stdout);
		fflush(stdout);
		usleep(100000);
	}

	fclose(fp);
	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <unistd.h>

// ./a.out file_1.c
// argv[0] argv[1]
int main( int argc, char **argv)
{
	FILE *fp;
	int ch;
	int count=0;
	fp = fopen(argv[1], "r");

	while ( (ch = fgetc( fp )) != EOF )
	{
		fputc(ch, stdout);
		fflush(stdout);
		usleep(100000);
	}

	fclose(fp);
	return 0;
}
#endif
