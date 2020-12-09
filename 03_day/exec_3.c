#include <unistd.h>

int main()
{
	char *argv[] = {"newpgm", "one", "two", (char*)0};
	char *envp[] = {"name=hong", "addr=seoul", (char*)0};
	execve("./newpgm", argv, envp );
	return 0;
}
