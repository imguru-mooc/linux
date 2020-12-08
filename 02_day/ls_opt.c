#if 1 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/sysmacros.h>
#include <stdio.h>

#define  a_option  1
#define  l_option  2
#define  i_option  4
#define  R_option  8

int get_width( int size )
{
	int i;
	for(i=0; size ;i++ )
		size /= 10;
	return i;
}

void my_ls( char *path, int flags )
{
	DIR *dp;
	struct stat buf;
	char rwx[] = "rwx";
	char sst[] = "sst";
	int i;
	struct dirent *p;
	struct passwd *pwd;
	struct group *grp;
	struct tm *tmp;
	int size_width=0;

	chdir( path );

	dp = opendir(".");

	while( p = readdir(dp))
	{
		int width=0;


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

		if( !(flags & a_option) )
		{
			if( p->d_name[0] == '.' )
				continue;
		}

		stat( p->d_name, &buf);
		if( flags & i_option )
			printf("%lu ", buf.st_ino);

		if( flags & l_option )
		{
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

			if( perm[0] == 'c' || perm[0] == 'b' )
				printf("%3u, %3u ", major(buf.st_rdev), 
						minor(buf.st_rdev));
			else
				printf("%*ld ", size_width, buf.st_size);
			tmp = localtime( &buf.st_mtime );
			printf("%02d월  %d %02d:%02d ", 
					tmp->tm_mon+1, tmp->tm_mday,
					tmp->tm_hour, tmp->tm_min);
		}
		printf("%s\n", p->d_name);
	}
}

int main( int argc, char **argv )
{
	int opt;
	int flags=0;
	while( (opt = getopt(argc, argv, "aliR" )) != -1 )
	{
		if( opt == 'a' ) flags |= a_option;
		if( opt == 'l' ) flags |= l_option;
		if( opt == 'i' ) flags |= i_option;
		if( opt == 'R' ) flags |= R_option;
	}
	//printf("%x\n" , flags );
	my_ls(argv[1], flags);
	return 0;
}
#endif

#if 0 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
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
	struct tm *tmp;
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
		tmp = localtime( &buf.st_mtime );
		printf("%02d월  %d %02d:%02d ", 
			tmp->tm_mon+1, tmp->tm_mday,
			tmp->tm_hour, tmp->tm_min);
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
