#include "headers.h"

int x = 0;
pthread_mutex_t key;

void sum(){
    for(int i=1; i<=100; i++){

        pthread_mutex_lock(&key);
        x = x+1; //critical section
        printf("j: %d. Aafter Sumation: %d\n",i, x);
        pthread_mutex_unlock(&key);

    }
}

void sub(){
    for(int i=1; i<=100; i++){

        pthread_mutex_lock(&key);
        x = x-1; //critical section
        printf("i: %d. Aafter subtraction: %d\n",i, x);
        pthread_mutex_unlock(&key);

    }
}

int main(){
    //sum();
    //sub();
    
    pthread_mutex_init(&key, NULL);


    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, (void *) sum, NULL);
    pthread_create(&tid2, NULL, (void *) sub, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("Main thread will terminate now. \n");

    exit(EXIT_SUCCESS);
}