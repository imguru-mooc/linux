#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

void my_ls( char *dname )
{
	DIR *dp;
	struct dirent *p;

	chdir(dname); 
	dp = opendir("."); 
	while( p = readdir( dp ))
		printf("%s\n", p->d_name);
	closedir(dp);
	chdir(".."); 
}

int main()
{
	my_ls(".");
	return 0;
}
