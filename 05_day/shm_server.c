#include "shmlib.h"
#include <stdio.h>
#include <string.h>

int main()
{
	int mid;
	mid = CreateSHM(8000);
	SHM_t *p;
	p = GetPtrSHM(mid);
	strcpy( p->name, "keyboard" );
	p->gpio = 210;
	getchar();
	FreePtrSHM(p);
	RemoveSHM(mid);
	return 0;
}
