#if 1
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <setjmp.h>

/*
typedef struct
{
	long int __jmp_buf[6];
} jmp_st;

typedef jmp_st jmp_buf[1];
jmp_buf env;

setjmp(env);
*/

jmp_buf env;

void foo()
{
	int fd;
	fd = open("xxx", O_RDONLY);
	if( fd < 0 )
		longjmp(env, 1);  // throw 1
}

int main()
{
	int ret;
    if( (ret = setjmp(env)) == 0 ) // try
	{
		while(1)
		{
			while(1)
			{
				foo();
			}
		}
	}
	else if( ret == 1 )  // catch(1)
	{
		printf("ret=%d\n", ret );
		perror("open()\n");
		return -1;
	}
	return 0;
}
#endif
#if 0
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

void foo()
{
	int fd;
	fd = open("xxx", O_RDONLY);
	if( fd < 0 )
		goto err;
}

int main()
{
	while(1)
	{
		while(1)
		{
			foo();
		}
	}
	return 0;

err:
	perror("open()\n");
	return -1;
}
#endif
#if 0
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd;

	while(1)
	{
		while(1)
		{
			fd = open("xxx", O_RDONLY);
			if( fd < 0 )
				goto err;
		}
	}
	return 0;

err:
	perror("open()\n");
	return -1;
}
#endif

#if 0
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd;

	while(1)
	{
		fd = open("xxx", O_RDONLY);
		if( fd < 0 )
			break;
	}
	if( fd < 0 )
		perror("open()\n");

	return 0;
}
#endif

#if 0
int main()
{
	try
	{
	}
	catch(e)
	{
	}
	return 0;
}
#endif
