#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t w,rd;
int cpd=1;
int nr=0;

void *readin(void *readno);
void *writein(void *writeno);

int main()
{
	sem_init(&rd, 0,1);
    sem_init(&w,0,1);
	int per[5] = {1,2,3,4,5};
    pthread_t read[5],write[3];
    for(int i = 0; i < 5; i++) {
        pthread_create(&read[i], NULL, (void *)readin, (void *)&per[i]);
    }
        for(int i = 0; i < 3; i++) {
        pthread_create(&write[i], NULL, (void *)writein, (void *)&per[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(read[i], NULL);
    }
    for(int i = 0; i < 3; i++) {
        pthread_join(write[i], NULL);
    }
    sem_destroy(&rd);
    sem_destroy(&w);
    return 0;

}

void *writein(void *writeno)
{
    sem_wait(&w);
    cpd=cpd+1;
    printf("Data written by Writer %d to %d\n",(*((int *)writeno)),cpd);
    sem_post(&w);

}

void *readin(void *readno)
{
    sem_wait(&rd);
    nr++;
    if(nr == 1) {
        sem_wait(&w);
    }
    sem_post(&rd);
    printf("Data read by Reader %d as %d\n",*((int *)readno),cpd);
    sem_wait(&rd);
    nr--;
    if(nr == 0) {
        sem_post(&w);
    }
    sem_post(&rd);
}
