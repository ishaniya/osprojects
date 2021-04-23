#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<semaphore.h>

sem_t sema1,sema2,sema3;

void *function1()
{
        sem_wait(&sema1);
        printf("Thread : 1 using Semaphore : 1\n");
        sem_wait(&sema2);
        printf("\nThread : 1 using Semaphore : 2\n");
        sem_wait(&sema3);
        printf("\nThread : 1 using Semaphore : 3\n");
        sem_post(&sema3);
        printf("\nThread : 1 releasing Semaphore : 3\n");
        sem_post(&sema2);
        printf("\nThread : 1 releasing Semaphore : 2\n");
        sem_post(&sema1);
        printf("\nThread : 1 releasing Semaphore : 1\n");                                                                                                     
		}

void *function2()
{                                                                                                                                                                                                                         
		sem_wait(&sema3);                                                                                                                                                                                                 
		printf("Thread : 2 using Semaphore : 3\n");                                                                                                                                                                        
		sem_wait(&sema2);
        printf("\nThread : 2 using Semaphore : 2\n");
        sem_wait(&sema1);
        printf("\nThread : 2 using Semaphore : 1\n");
        sem_post(&sema1);
        printf("\nThread : 2 releasing Semaphore : 1\n");
        sem_post(&sema2);
        printf("\nThread : 2 releasing Semaphore : 2\n");
        sem_post(&sema3);
        printf("\nThread : 2 releasing Semaphore : 3");

}
void *function3()
{
        sem_wait(&sema2);
        printf("Thread : 3 using Semaphore : 2\n");
        sem_wait(&sema1);
        printf("\nThread : 3 using Semaphore : 1\n");
        sem_wait(&sema3);
        printf("\nThread : 3 using Semaphore : 3\n");
        sem_post(&sema3);
        printf("\nThread : 3 releasing Semaphore : 3\n");
        sem_post(&sema1);
        printf("\nThread : 3 releasing Semaphore : 1\n");
        sem_post(&sema2);
    }


int main()
{
        sem_init(&sema1,0,1);
        sem_init(&sema2,0,1);
        sem_init(&sema3,0,1);
        pthread_t the1,the2,the3;
        pthread_create(&the1,NULL,function1,NULL);
        pthread_create(&the2,NULL,function2,NULL);
		pthread_join(the1,NULL);
        pthread_join(the2,NULL);
        pthread_join(the3,NULL);                                                                                                                                                                                                                                                                                                                                                                                                     
}
