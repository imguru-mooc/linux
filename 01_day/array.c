#if 1
#include <stdio.h>

int main()
{
	int a[4];
	//int (*p)[4]  = &a;
	int *p = &a;
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[4];
	int *p = &a;
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[4];
	int *p = a;
	printf("a  =%p\n", a);
	printf("a+1=%p\n", a+1);

	printf("&a  =%p\n", &a);
	printf("&a+1=%p\n", &a+1);
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[4];
	int *p = a;
	printf("sizeof(a)=%lu\n", sizeof(a));
	printf("sizeof(int[4])=%lu\n", sizeof(int[4]));
	printf("sizeof(p)=%lu\n", sizeof(p));
	printf("sizeof(int*)=%lu\n", sizeof(int*));
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[4];
	int *p = a;
	printf("sizeof(a)=%lu\n", sizeof(a));
	printf("sizeof(p)=%lu\n", sizeof(p));
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	int a[2];
	int *p = a;
	printf("sizeof(p)=%lu\n", sizeof(p));
	return 0;
}
#endif

#if 0
#include <stdio.h>

int main()
{
	int a[2];
	printf("sizeof(a)=%lu\n", sizeof(a));
	return 0;
}
#endif
