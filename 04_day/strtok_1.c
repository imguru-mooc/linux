#include <stdio.h>
#include <string.h>
int main()
{
	char ip[] = ".....192......168.....56.....101....";
	char *p;

	p = strtok(ip, ".");
	while(p)
	{
		printf("[%s]\n", p );
		p = strtok(0, ".");
	}
	return 0;
}
