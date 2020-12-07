#if 1
#include <stdio.h>

typedef struct
{
	signed char ch:1;
}ST;

int main()
{
	ST s;
	s.ch = 1;  // 1
	printf("%d\n", s.ch);  // -1
	return 0;
}
#endif

#if 0
#include <stdio.h>

typedef struct
{
	signed char ch:2;
}ST;

int main()
{
	ST s;
	//s.ch = 3;
	s.ch = 2;  // 10
	printf("%d\n", s.ch);
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	//signed short ch=0xfffe;  // 11111111 11111110 -2
	signed short ch=0xffff;  // 11111111 11111111 -1
	printf("%d\n", ch);
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	//signed char ch=255;  // 11111111 -1
	//                     // 00000001
	signed char ch=0xff;   // 11111111 -1
	printf("%d\n", ch);
	return 0;
}
#endif
#if 0
#include <stdio.h>

int main()
{
	signed char ch=250;
	printf("%d\n", ch);
	return 0;
}
#endif
