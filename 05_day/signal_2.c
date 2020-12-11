#if 1
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main()
{
	int i;
	sigset_t set;
	sigset_t oldset;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_BLOCK, &set, &oldset);
	for(i=0; i<3; i++ )
	{
		sleep(1);
		printf(".\n");
	}
	sigprocmask(SIG_SETMASK, &oldset, 0);
	while(1)
		pause();
	return 0;
}
#endif


