#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void alm(int signo)
{
	printf("SIGALRM Receive\n");
}

int main()
{
	signal(SIGALRM, alm);
	alarm(3); 
	printf("process id pause\n");
	pause();
	printf("process is wakeup\n");
	return 0;
}

