#include "./CThreadBase.h"


CThreadBase::CThreadBase()
{
	tid = -1;
}

CThreadBase::~CThreadBase()
{
	
}

bool CThreadBase::Create()
{
	int trl;
	trl = pthread_create(&tid, NULL, doPthread, this);
	if (trl == -1)
	{
		perror("pthread create fail.");
	}
	return (trl == -1) ? false : true;
}

void CThreadBase::Run()
{
	printf("Thread Base running.\n");
}

void* CThreadBase::doPthread(void *pSelf)
{
	pthread_detach(pthread_self());
	((CThreadBase*)pSelf)->Run();
}
