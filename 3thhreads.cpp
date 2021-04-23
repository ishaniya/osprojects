#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include<semaphore.h>

void *fun1();
void *fun2();
void *fun3();

sem_t s1,s2,s3;

int main()                                                                                                              
{                                                                                                                               
		sem_init(&s1,0,1);
        sem_init(&s2,0,1);
        sem_init(&s3,0,1);

        pthread_t thread1,thread2,thread3;
        pthread_create(&thread1,NULL,fun1,NULL);
        pthread_create(&thread2,NULL,fun2,NULL);
        pthread_create(&thread3,NULL,fun2,NULL);
        pthread_join(fun1,NULL);                                                                                                
		pthread_join(fun2,NULL);                                                                                                
		pthread_join(fun3,NULL);
		
}                                                                                                                       
void *fun1()
{
        sem_wait(&s1);
        printf("thread one acquired semaphore 1");
        sleep(1);
        sem_wait(&s2);                                                                                                          
		printf("\nthread one acquired semaphore 2");                                                                            
		sleep(1);
        sem_wait(&s3);
        printf("\nthread one acquired semaphore 3");
        
        sem_post(&s1);                                                                                                          
		printf("\nthread one release semaphore 1");
		
		sem_post(&s2);                                                                                                          
		printf("\nthread one release semaphore 2");
		
		sem_post(&s3);                                                                                                          
		printf("\nthread one release semaphore 3");
		
}


void *fun2()
{
        sem_wait(&s1);
        printf("thread two acquired semaphore 1");
        sleep(1);
        sem_wait(&s2);                                                                                                          
		printf("\nthread two acquired semaphore 2");                                                                            
		sleep(1);
        sem_wait(&s3);
        printf("\nthread two acquired semaphore 3");
        
        sem_post(&s1);                                                                                                          
		printf("\nthread two release semaphore 1");
		
		sem_post(&s2);                                                                                                          
		printf("\nthread two release semaphore 2");
		
		sem_post(&s3);                                                                                                          
		printf("\nthread two release semaphore 3");
		
}


void *fun3()
{
        sem_wait(&s1);
        printf("thread three acquired semaphore 1");
        sleep(1);
        sem_wait(&s2);                                                                                                          
		printf("\nthread three acquired semaphore 2");                                                                            
		sleep(1);
        sem_wait(&s3);
        printf("\nthread three acquired semaphore 3");
        
        sem_post(&s1);                                                                                                          
		printf("\nthread three release semaphore 1");
		
		sem_post(&s2);                                                                                                          
		printf("\nthread three release semaphore 2");
		
		sem_post(&s3);                                                                                                          
		printf("\nthread three release semaphore 3");
		
}
        
