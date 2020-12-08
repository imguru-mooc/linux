#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	struct stat buf;
	char perm[] = "----------";
	char rwx[] = "rwx";
	char sst[] = "sst";
	int i;
	stat( argv[1], &buf);

	if( S_ISDIR(buf.st_mode) ) perm[0]  = 'd';
	if( S_ISCHR(buf.st_mode) ) perm[0]  = 'c'; 
	if( S_ISBLK(buf.st_mode) ) perm[0]  = 'b';
	if( S_ISFIFO(buf.st_mode) ) perm[0] = 'p';
	if( S_ISSOCK(buf.st_mode) )perm[0]  = 's';
	if( S_ISLNK(buf.st_mode) ) perm[0]  = 'l';


	for(i=0; i<9; i++)
		if( (buf.st_mode>>(8-i)) & 1 )
			perm[i+1] = rwx[i%3];

	for(i=0; i<3; i++)
	{
		if( (buf.st_mode>>(11-i)) & 1 )
		{
			if( perm[(i+1)*3] == '-' )
				perm[(i+1)*3] = sst[i]-32;
			else
				perm[(i+1)*3] = sst[i];
		}
	}

	printf("%s\n", perm );
	return 0;
}
