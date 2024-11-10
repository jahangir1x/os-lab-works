#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

const int TOTAL_ITEMS = 5;
int buffer[TOTAL_ITEMS];
int current_item_idx = 0;

sem_t buffer_semaphore;

void* producer(void* arg) {
    int item = 0;
    while (1) {
        item++;
        if (current_item_idx < TOTAL_ITEMS) {
            buffer[current_item_idx] = item;
            current_item_idx++;
            printf("producer produced: %d\n", item);
        } else {
            printf("buffer is full... waiting...");
        }
        sem_post(&buffer_semaphore);

        sleep(1);
    }
}

void* consumer(void* arg) {
    while (1) {
        sem_wait(&buffer_semaphore);
        if (current_item_idx > 0) {
            current_item_idx--;
            int item = buffer[current_item_idx];
            printf("consumer consumed: %d\n", item);
        } else {
            printf("buffer is empty... waiting...");
        }

        sleep(3);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&buffer_semaphore, 0, 0);

    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    sem_destroy(&buffer_semaphore);

    return 0;
}