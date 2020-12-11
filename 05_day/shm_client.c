#include "shmlib.h"
#include <stdio.h>
#include <string.h>

int main()
{
	int mid;
	mid = OpenSHM(8000);
	SHM_t *p;
	p = GetPtrSHM(mid);
	printf("name=%s, gpio=%d\n", p->name, p->gpio);
	FreePtrSHM(p);
	return 0;
}
