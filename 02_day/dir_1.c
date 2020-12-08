#include <stdio.h>
#include <dirent.h>
int main()
{
	DIR *dp;
	struct dirent *p;
	dp = opendir(".");
	while( p = readdir( dp ))
		printf("%s\n", p->d_name);
	closedir(dp);

	return 0;
}
