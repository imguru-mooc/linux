#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int CreateSEM(key_t semkey);
int p(int semid);
int v(int semid);
