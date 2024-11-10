#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t thread1, thread2;
int money = 0;

void* thread1_function(void* arg) {
    for (int i = 0; i < 1e7; i++) {
        money++;
    }

    return NULL;
}

void* thread2_function(void* arg) {
    for (int i = 0; i < 1e7; i++) {
        money--;
    }
    return NULL;
}

int main() {
    pthread_create(&thread2, NULL, thread2_function, NULL);
    pthread_create(&thread1, NULL, thread1_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("%d\n", money);

    return 0;
}
