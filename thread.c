#include<stdio.h>
#include<pthread.h>

void* thrfun();
int count;
pthread_mutex_t mutex;

int main()
{
        pthread_t thread[50];
        pthread_mutex_init(&mutex,NULL);
        int i;
        for(i=0;i<50;i++)
        {
                pthread_create(&thread[i],NULL,thrfun,NULL);
        }

        for(i=0;i<50;i++)
        {
                pthread_join(thread[i],NULL);
        }

        pthread_mutex_destroy(&mutex);
        printf("\nTotal count:%d\n",count);

}

void* thrfun()
{
        int j;

        for(j=0;j<1000;j++)
        {
                pthread_mutex_lock(&mutex);
                count++;
                printf("%d\t\t",count);
                pthread_mutex_unlock(&mutex);
        }

        printf("\n\n...................................\n");
}

