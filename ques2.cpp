#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int s=2;
pthread_mutex_t l;

void *function1()
{
        int x;
        pthread_mutex_lock(&l);
        x=s;
        x++;
        s=x;
        printf("Value after first thread: %d",s);
        pthread_mutex_unlock(&l);
}

void *function2()
{
        int y;
        pthread_mutex_lock(&l);
        y=s;
        y--;
        sleep(1);
        s=y;
        printf("\nValue after second thread : %d",s);
        pthread_mutex_unlock(&l);
}

int main()
{
        pthread_mutex_init(&l, NULL);
        pthread_t t1, t2;
        pthread_create(&t1, NULL, function1, NULL);
        pthread_create(&t2, NULL, function2, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2,NULL);
        printf("\nFinal value : %d\n",s);
}




