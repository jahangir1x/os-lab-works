// main.c
#include <execinfo.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Thread is about to exec a new program.\n");
    execlp("./sample", NULL);
    return NULL;
}

int main() {
    pthread_t thread;

    if (pthread_create(&thread, NULL, thread_function, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    sleep(9999);

    pthread_join(thread, NULL);

    printf("This line will not be printed if exec() is successful.\n");

    return 0;
}
