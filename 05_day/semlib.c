#include "semlib.h"

int CreateSEM(key_t semkey)
{
	int status=0,semid;
	if((semid = semget(semkey,1, 0666|IPC_CREAT|IPC_EXCL))==-1)
	{
		if(errno==EEXIST)
			semid = semget(semkey,1,0);
	} else
		status = semctl(semid,0,SETVAL,2);

	if(semid==-1 || status==-1)
		return 1;

	return semid;
}

int p(int semid)
{
	struct sembuf p_buf;
	p_buf.sem_num = 0;
	p_buf.sem_op  = -1;
	p_buf.sem_flg = SEM_UNDO;
	if(semop(semid,&p_buf,1)==-1 )
		return -1;
	return 0;
}

int v(int semid)
{
	struct sembuf p_buf;
	p_buf.sem_num = 0;
	p_buf.sem_op  = 1;
	p_buf.sem_flg = SEM_UNDO;
	if(semop(semid,&p_buf,1)==-1 )
		return -1;
	return 0;
}
