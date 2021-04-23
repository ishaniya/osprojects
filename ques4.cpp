#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define mi 5
#define BS 5

void *produce();
void *consume();
sem_t emp,ful;
int inside = 0, outside = 0;
int buffer[BS];
pthread_mutex_t l;

int x=0;

int main()
{
	pthread_t p,c;
    pthread_mutex_init(&l, NULL);
	sem_init(&emp,0,BS);
    sem_init(&ful,0,0);
    int n;
    printf("Choose \n");
    printf("\n1.Consume\n2.Produce\n3.Quit");
	while(1)
        {
                printf("\nEnter :");
                scanf("%d",&n);
                switch(n)
                {
                	
                		case 2: if(x!=0)
                                {
                                                pthread_create(&c, NULL,consume,NULL);
                                                pthread_join(c,NULL);
                                }                                                                                                                                                                                                                  else

                                                printf("Empty Buffer");
                                break;
                                
                        case 1:if(x!=5)
                                {
                                                pthread_create(&p, NULL,produce,NULL);
                                                pthread_join(p,NULL);
                                }
                                else
                                                printf("Buffer is full");
                                break;
                        case 3:
                                        exit(0);
                                        break;
                }
        }
    pthread_mutex_destroy(&l);
    sem_destroy(&emp);
    sem_destroy(&ful);

    return 0;

}

void *produce()
{
    	int item=1;
    	x++;
        sem_wait(&emp);
        pthread_mutex_lock(&l);
        buffer[inside] = item;
        printf("Producer produces %d item at %d\n", buffer[inside],inside+1);
        inside = (inside+1)%BS;
        pthread_mutex_unlock(&l);
        sem_post(&ful);
      
}
void *consume()
{
		x--;
        sem_wait(&ful);
        pthread_mutex_lock(&l);
        int item = buffer[outside];
        printf("Consumer removes %d item from %d\n",item, outside+1);
        outside = (outside+1)%BS;
        pthread_mutex_unlock(&l);
        sem_post(&emp);
}
