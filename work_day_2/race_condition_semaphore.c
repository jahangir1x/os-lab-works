#include "headers.h"

int x = 0;
sem_t sem;

void sum(){
    for(int i=1; i<=100; i++){
        sem_wait(&sem);
        x = x + 1; //critical section
        printf("j: %d. After Summation: %d\n", i, x);
        sem_post(&sem);
    }
}

void sub(){
    for(int i=1; i<=100; i++){
        sem_wait(&sem);
        x = x - 1; //critical section
        printf("i: %d. After Subtraction: %d\n", i, x);
        sem_post(&sem);
    }
}

int main(){
    sem_init(&sem, 0, 1);

    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, (void *) sum, NULL);
    pthread_create(&tid2, NULL, (void *) sub, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&sem);

    printf("Main thread will terminate now.\n");

    return 0;
}
