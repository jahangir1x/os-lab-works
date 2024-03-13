#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x = 5, y = 2;
int result = 0;

void sum() {
    // int result;
    for (int i = 0; i < 20000; i++) {
        result = result + x + y;
        printf("i: %d x+y: %d result: %d\n", i, x + y, result);
    }
}

void subtract() {
    // int result;
    for (int j = 0; j < 20000; j++) {
        result = result + x - y;
        printf("j: %d x-y: %d result: %d\n", j, x - y, result);
    }
}

int main() {
    // sum();
    // subtract();
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, (void *)sum, NULL);
    pthread_create(&tid2, NULL, (void *)subtract, NULL);
    // printf("%lu, %lu\n", tid1, tid2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("result: %d", result);
    exit(0);
}