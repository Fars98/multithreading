#include<stdio.h>
#include<pthread.h>

void* thrfun();
int main()
{
	pthread_t thread1;
	pthread_create(&thread1,NULL,thrfun,NULL);
	pthread_join(thread1,NULL);
	printf("Thread ID:%ld\n",thread1);
	//pthread_join(thread1,NULL);
	return 0;
}

void* thrfun()
{
	printf("Thread function\n");
	return NULL;
}
