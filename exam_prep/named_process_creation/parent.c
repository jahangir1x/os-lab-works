#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 == 0) {
        execlp("./child_1", "child_1", NULL);
        perror("Failed to execute child_1");
        exit(1);
    }

    pid2 = fork();
    if (pid2 == 0) {
        execlp("./child_2", "child_2", NULL);
        perror("Failed to execute child_2");
        exit(1);
    }

    pid3 = fork();
    if (pid3 == 0) {
        execlp("./child_3", "child_3", NULL);
        perror("Failed to execute child_3");
        exit(1);
    }

    sleep(9999);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Parent: All child processes have finished.\n");

    return 0;
}
