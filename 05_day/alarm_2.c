#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void alm(int signo)
{
	printf("베팅 시간 만료\n");
}

int main()
{
	int ret;
	int i;
	int temp;
	char buff[512];
	signal(SIGALRM, alm);
	for(i=0; i<5 ;i++)
	{
		printf("%d번째 게이머 배팅 : \n", i+1);
		alarm(5); 
		ret = read(0, buff, sizeof buff );
		temp = alarm(0); 
		write( 1, buff, ret );
	}
	return 0;
}

