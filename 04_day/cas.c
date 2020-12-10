#include <stdio.h>

typedef int int32_t;

int __bionic_cmpxchg(int32_t old_value, int32_t new_value, volatile int32_t* ptr)
{
    int32_t prev;
    __asm__ __volatile__ ("lock; cmpxchgl %1, %2"
                          : "=a" (prev)
                          : "q" (new_value), "m" (*ptr), "0" (old_value)
                          : "memory");
    return prev != old_value;
}

int mutex=0;

int main()
{
	int ret;
	ret = __bionic_cmpxchg( 0, 1, &mutex);
	printf("mutex=%d\n", mutex );
	printf("ret=%d\n", ret );
	return 0;
}
