// main.c
#include <execinfo.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Thread running.\n");
    sleep(9999);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_function, NULL) != 0;
    pthread_create(&thread2, NULL, thread_function, NULL) != 0;

    int pid = fork();
    if (pid == 0) {
        execlp("./sample", NULL);
    } else {
        printf("parent program sleeping...");
        sleep(9999);

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
    }

    return 0;
}
