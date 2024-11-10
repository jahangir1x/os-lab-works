#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_ITERATIONS 1000000

int shared_counter = 0;
pthread_mutex_t lock;

void* increment_counter(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(&lock);
        shared_counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrement_counter(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(&lock);
        shared_counter--;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL);

    if (pthread_create(&thread1, NULL, increment_counter, NULL) != 0) {
        perror("Failed to create Thread 1");
        return EXIT_FAILURE;
    }

    if (pthread_create(&thread2, NULL, decrement_counter, NULL) != 0) {
        perror("Failed to create Thread 2");
        return EXIT_FAILURE;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final value of shared_counter: %d\n", shared_counter);

    pthread_mutex_destroy(&lock);

    return 0;
}
