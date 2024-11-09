#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {
        printf("Parent process (PID: %d) created a child process (PID: %d)\n", getpid(), pid);
        printf("Parent process (PID: %d) is terminating\n",

               getpid());
        exit(0);
    } else {
        sleep(5);
        printf("Child process (PID: %d) is running and has become an orphan (PPID: %d)\n", getpid(), getppid());

        sleep(10);
        printf("Child process (PID: %d) is terminating\n",

               getpid());
    }

    return 0;
}