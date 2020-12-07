
#if 1
#include <stdio.h>

void foo(void)
{
   printf("foo()\n");
}

int main()
{
    void (*p)(void) = foo;
	p();
    return 0;
}
#endif
#if 0
#include <stdio.h>

void foo(void)
{
   printf("foo()\n");
}

int main()
{
    foo;
    return 0;
}
#endif
#if 0
#include <stdio.h>

void foo(void)
{
   printf("foo()\n");
}

int main()
{
    foo();
    return 0;
}
#endif
