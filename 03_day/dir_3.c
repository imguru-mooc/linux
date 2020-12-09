#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void my_ls( char *dname )
{
	DIR *dp;
	struct dirent *p;
	struct stat buf;

	chdir(dname); 
	dp = opendir("."); 
	printf("\n%s:\n", dname);
	while( p = readdir( dp ))
	{
		printf("%s ", p->d_name);
	}
	printf("\n");
	rewinddir(dp);
	while( p = readdir( dp ))
	{
		lstat( p->d_name, &buf );
		if( S_ISDIR(buf.st_mode) )
		{
			if( strcmp(p->d_name, ".") && strcmp(p->d_name, "..") )
				my_ls( p->d_name );
		}
	}
	closedir(dp);
	chdir(".."); 
}

int main()
{
	my_ls(".");
	return 0;
}
