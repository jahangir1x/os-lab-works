#include "headers.h"

int main() {
    pid_t child_1, child_2, child_3;

    prctl(PR_SET_NAME, "parent_process", 0, 0, 0);

    printf("Parent Process: %d\n", getpid());

    child_1 = fork();
    if (child_1 == 0) {
        prctl(PR_SET_NAME, "child_1", 0, 0, 0);
        printf("Child 1 Process: %d, Parent: %d\n", getpid(), getppid());
        exit(0);
    }

    child_2 = fork();
    if (child_2 == 0) {
        prctl(PR_SET_NAME, "child_2", 0, 0, 0);
        printf("Child 2 Process: %d, Parent: %d\n", getpid(), getppid());
        exit(0);
    }

    child_3 = fork();
    if (child_3 == 0) {
        prctl(PR_SET_NAME, "child_3", 0, 0, 0);
        printf("Child 3 Process: %d, Parent: %d\n", getpid(), getppid());
        exit(0);
    }

    sleep(9999);
    wait(NULL);
    wait(NULL);
    wait(NULL);

    printf("Parent Process: All child processes finished.\n");

    return 0;
}
