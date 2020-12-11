#include "semlib.h"
#include <stdio.h>

int main()
{
	int sid;

	sid = CreateSEM(7000);

	p(sid);
	printf("임계영역 진입\n");
	getchar();
	v(sid);
	printf("임계영역 탈출\n");
	return 0;
}
