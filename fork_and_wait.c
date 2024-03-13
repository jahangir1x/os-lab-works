#include <stdio.h>
#include <unistd.h>
int main() {
    int childPID;

    // create a new process
    childPID = fork();
    if (childPID == 0) {  // child process part
        printf("I am child process\n=================\n");
        while (1) {
            printf("child");
        }

    } else {  // parent process part
        printf("I am parent process\n=================\n");
        for (int i = 0; i < 1e9; i++) {
        }
        wait(NULL);
    }
}