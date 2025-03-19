#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *mythread1(void *vargp)
{
	printf("thread1\n");
	for(int i=0;i<=10;i++)
	{
		printf("i=%d\n",i);
	}
	printf("Exit from thread1\n");
	return NULL;
}
void *mythread2(void *vargp)
{
	printf("thread2\n");
	for(int j=0;j<=10;j++)
	{
		printf("j=%d\n",j);
	}
	printf("Exit from thread2\n");
	return NULL;
}
int main()
{
	pthread_t tid;
	printf("Before thread creation\n");
	pthread_create(&tid,NULL,mythread1,NULL);
	pthread_create(&tid,NULL,mythread2,NULL);
	pthread_join(tid,NULL);
	pthread_join(tid,NULL);
	exit(0);
}
