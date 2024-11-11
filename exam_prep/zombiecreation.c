#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();

    if (pid > 0) {
        printf("Parent process (PID: %d) created a child process (PID: %d)\n", getpid(), pid);
        sleep(1000);
        printf("Parent process (PID: %d) is now terminating, cleaning up zombie child\n", getpid());
    } else {
        printf("Child process (PID: %d) is terminating\n",

               getpid());
        exit(0);
    }

    return 0;
}