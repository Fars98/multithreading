#include<stdio.h>
#include<pthread.h>

void* thrfun();
int count;

int main()
{
        pthread_t thread[50];
        int i;
        for(i=0;i<50;i++)
        {
                pthread_create(&thread[i],NULL,thrfun,NULL);
        }

        for(i=0;i<50;i++)
        {
                pthread_join(thread[i],NULL);
        }

        printf("\nTotal count:%d\n",count);

}

void* thrfun()
{
        int j;

        for(j=0;j<1000;j++)
        {
                count++;
                printf("%d\t\t",count);
        }

        printf("\n\n...................................\n");
}

