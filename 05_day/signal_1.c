#if 1
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

//#define  SIGINT   (2)
//typedef void (*handler_t)(int);
//handler_t signal( int, handler_t );
handler_t old;

void my_sig(int signo)
{
	printf("my_sig(%d)\n", signo);
	signal( SIGINT, old );
}

int main()
{
	SIG_DFL;
	SIG_IGN;
	old = signal( SIGINT, my_sig );
	while(1)
		pause();
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>

#define  SIGINT   (2)
void (*signal( int, void (*)(int) ))(int);
void (*old)(int);

void my_sig(int signo)
{
	printf("my_sig(%d)\n", signo);
	signal( SIGINT, old );
}

int main()
{
	old = signal( SIGINT, my_sig );
	while(1)
		pause();
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <stdio.h>

#define  SIGINT   (2)

void signal( int, void (*)(int) );

void my_sig(int signo)
{
	printf("my_sig(%d)\n", signo);
}

int main()
{
	signal( SIGINT, my_sig );
	while(1)
		pause();
	return 0;
}
#endif

#if 0
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void my_sig(int signo)
{
	printf("my_sig(%d)\n", signo);
}

int main()
{
	signal( SIGINT, my_sig );
	while(1)
		pause();
	return 0;
}
#endif
#if 0
#include <unistd.h>
#include <signal.h>

int main()
{
	signal( SIGINT, SIG_IGN );
	signal( SIGQUIT, SIG_IGN );
	signal( SIGKILL, SIG_IGN );
	while(1)
		pause();
	return 0;
}
#endif

#if 0
#include <unistd.h>

int main()
{
	while(1)
		pause();
	return 0;
}
#endif
