#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int status;
	fork(&status);

	if( status == 1 )
		printf("parent : after\n");
	else if ( status == 2 )
		printf("child  : after\n");
	return 0;
}
