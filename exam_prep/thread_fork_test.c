#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("in thread");
    sleep(9999);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3, thread4;

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    pid_t pid = fork();

    printf("shared code");

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {  // Child process
        printf("In child process after fork.\n");
        pthread_create(&thread3, NULL, thread_function, NULL);
        pthread_create(&thread4, NULL, thread_function, NULL);
    } else {  // Parent process
        wait(NULL);
    }

    sleep(9999);

    // Join threads to clean up in parent
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Parent process finished.\n");
    return 0;
}