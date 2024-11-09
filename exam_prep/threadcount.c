#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void* thread_function(void* arg) {
    printf("Thread %ld is running.\n", (long)arg);
    sleep(9999);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // pthread_create(&thread1, NULL, thread_function, (void*)1);
    pthread_create(&thread2, NULL, thread_function, (void*)2);

    printf("Main thread calling fork...\n");

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // printf("In child process after fork.\n");

        // printf("Child process - thread1 status: ");
        // if (pthread_kill(thread1, 0) == 0) {
        //     printf("Alive\n");
        // } else {
        //     printf("Does not exist\n");
        // }

        // printf("Child process - thread2 status: ");
        // if (pthread_kill(thread2, 0) == 0) {
        //     printf("Alive\n");
        // } else {
        //     printf("Does not exist\n");
        // }
        // _exit(0);
    }

    sleep(9999);
    // pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Parent process finished.\n");
    return 0;
}
