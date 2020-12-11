#include <sys/types.h>
#include <sys/shm.h>

typedef struct
{
	char name[20];
	int  gpio;
} SHM_t;

int CreateSHM(long key);
int OpenSHM(long key);
SHM_t *GetPtrSHM(int shmid);
int FreePtrSHM(SHM_t *shmptr);
int RemoveSHM(int shmid);
