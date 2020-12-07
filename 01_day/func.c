#if 1
#include <stdio.h>

//int (* aaa(void) )[3]
void *aaa(void)
{
	static int a[2][3];
    printf("aaa()\n");
	return a;
}

int main()
{
	void *p;
	p = aaa();
	((int(*)[3])p)[1][2]= 10;
    return 0;
}

#endif
#if 0
#include <stdio.h>

int (* aaa(void) )[3]
{
	static int a[2][3];
    printf("aaa()\n");
	return a;
}

int main()
{
	aaa()[1][2] = 10;
    return 0;
}

#endif
#if 0
#include <stdio.h>

void aaa(void) 
{
   printf("aaa()\n");
}

void* bbb(void)  
{
   printf("bbb()\n");
   return aaa;
}

int main()
{
	void *p;
	p = bbb();
	((void(*)(void))p)();
    return 0;
}

#endif
#if 0
#include <stdio.h>

typedef  void (*F1)(void);
typedef  F1 (*F2)(void);  
typedef  F2 (*F3)[2];

void aaa(void) 
{
   printf("aaa()\n");
}

F1 bbb(void)  
{
   printf("bbb()\n");
   return aaa;
}

int main()
{
	F2 p[2][2] = {{bbb,bbb},{bbb,bbb}};
	F3 q = p;
	q[1][1]()();
    return 0;
}

#endif
#if 0
#include <stdio.h>

typedef  void F1(void);
typedef  F1* F2;
typedef  F2 F3(void);  
typedef  F3* F4;
typedef  F4 F5[2];
typedef  F5* F6;

void aaa(void) 
{
   printf("aaa()\n");
}

F2 bbb(void)  
{
   printf("bbb()\n");
   return aaa;
}

int main()
{
	F4 p[2][2] = {{bbb,bbb},{bbb,bbb}};
	F6 q = p;
	q[1][1]()();
    return 0;
}

#endif
#if 0
#include <stdio.h>

void aaa(void) 
{
   printf("aaa()\n");
}

void (* bbb(void) )(void) 
{
   printf("bbb()\n");
   return aaa;
}

int main()
{
	void (* (*p[2][2])(void) )(void) = {{bbb,bbb},{bbb,bbb}};
	void (* (*(*q)[2])(void) )(void) = p;
	q[1][1]()();
    return 0;
}

#endif
#if 0
#include <stdio.h>

void aaa(void) 
{
   printf("aaa()\n");
}

void (* bbb(void) )(void) 
{
   printf("bbb()\n");
   return aaa;
}

int main()
{
	void (* (*p[2][2])(void) )(void) = {{bbb,bbb},{bbb,bbb}};
	p[1][1]()();
    return 0;
}

#endif
#if 0
#include <stdio.h>

void aaa(void) 
{
   printf("aaa()\n");
}

void (* bbb(void) )(void) 
{
   printf("bbb()\n");
   return aaa;
}

int main()
{
	void (* (*p[2])(void) )(void) = {bbb,bbb};
	p[1]()();
    return 0;
}

#endif
#if 0
#include <stdio.h>

void aaa(void) 
{
   printf("aaa()\n");
}

void (* bbb(void) )(void) 
{
   printf("bbb()\n");
   return aaa;
}

int main()
{
	void (* (*p)(void) )(void) = bbb;
	p()();
    return 0;
}

#endif
#if 0
#include <stdio.h>

void aaa(void) 
{
   printf("aaa()\n");
}

void (* bbb(void) )(void) 
{
   printf("bbb()\n");
   return aaa;
}

int main()
{
	bbb()();
    return 0;
}

#endif
#if 0
#include <stdio.h>

void aaa(void) 
{
   printf("aaa()\n");
}

int main()
{
	aaa();
    return 0;
}

#endif

#if 0
#include <stdio.h>

int (* foo(void) )[2]
{
   static int a[2][2] = {1,2,3,4};
   printf("foo()\n");
   return a;
}

int main()
{
    int (*p)[2];
    p = foo();
    p[1][1] = 10;
    return 0;
}

#endif
#if 0
#include <stdio.h>

int (*)[2] foo(void)
{
   static int a[2][2] = {1,2,3,4};
   printf("foo()\n");
   return a;
}

int main()
{
    int (*p)[2];
    p = foo();
    p[1][1] = 10;
    return 0;
}

#endif
#if 0
#include <stdio.h>

int* foo(void)
{
   static int a[2]= {1,2};
   printf("foo()\n");
   return a;
}

int main()
{
    int *p;
    p = foo();
    p[1] = 10;
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
