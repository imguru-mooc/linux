#if 1 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>

// 12345
// 1234
// 123
// 12
// 1
int get_width( int size )
{
	int i;
	for(i=0; size ;i++ )
		size /= 10;
	return i;
}

int main(int argc, char **argv)
{
	DIR *dp;
	struct stat buf;
	char rwx[] = "rwx";
	char sst[] = "sst";
	int i;
	struct dirent *p;
	struct passwd *pwd;
	struct group *grp;
	int size_width=0;
	dp = opendir(".");

	while( p = readdir(dp))
	{
		int width=0;
		if( p->d_name[0] == '.' )
			continue;

		stat( p->d_name, &buf);

		width = get_width(buf.st_size);
		if( width > size_width )
			size_width = width;
	}

	printf("size_width=%d\n", size_width);
	rewinddir(dp);

	while( p = readdir(dp))
	{
		char perm[] = "----------";
		if( p->d_name[0] == '.' )
			continue;

		stat( p->d_name, &buf);

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

		printf("%s ", perm );
		printf("%ld ", buf.st_nlink );

		pwd = getpwuid(buf.st_uid);
		printf("%s ", pwd->pw_name );

		grp = getgrgid(buf.st_gid);
		printf("%s ", grp->gr_name );

		printf("%*ld ", size_width, buf.st_size);
		printf("%s\n", p->d_name);
	}
	return 0;
}
#endif

#if 0 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	DIR *dp;
	struct dirent *p;
    dp = opendir(".");
	
    while( p = readdir(dp))
	{
		if( p->d_name[0] != '.' )
			printf("%s\n", p->d_name);
	}
	return 0;
}
#endif
