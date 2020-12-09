#include <unistd.h>

int main()
{
	//execl("/usr/bin/ls", "ls", "-l", (char*)0);
	execlp("ls", "ls", "-l", (char*)0);
	return 0;
}
