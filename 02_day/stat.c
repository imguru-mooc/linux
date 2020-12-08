#if 1
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	struct stat buf;
	stat( argv[1], &buf);

	if( S_ISREG(buf.st_mode) ) printf("-\n");
	if( S_ISDIR(buf.st_mode) ) printf("d\n");
	if( S_ISCHR(buf.st_mode) ) printf("c\n");
	if( S_ISBLK(buf.st_mode) ) printf("b\n");
	if( S_ISFIFO(buf.st_mode) ) printf("p\n");
	if( S_ISSOCK(buf.st_mode) ) printf("s\n");
	if( S_ISLNK(buf.st_mode) ) printf("l\n");
	return 0;
}
#endif

#if 0
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	struct stat buf;
	stat("xxx", &buf);

	if( (buf.st_mode>>12) == 0x8 )
		printf("Regular file\n");
	return 0;
}
#endif
