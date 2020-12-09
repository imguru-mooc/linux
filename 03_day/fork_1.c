#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	fork();
	printf("after\n");
	return 0;
}
