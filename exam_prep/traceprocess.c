#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;
    int var1 = 10, var2 = 5;
    printf("Parent Process: PID = %d\n", getpid());
    // First child process for addition
    pid1 = fork();
    if (pid1 < 0) {
        perror("Failed to fork first child process");
        exit(1);
    }
    if (pid1 == 0) {
        printf("Child Process 1 (Addition): PID = %d, PPID = %d\n", getpid(), getppid());
        int sum = var1 + var2;
        printf("Addition: %d + %d = %d\n", var1, var2, sum);
        for (int i = 0; i < 1e10; i++) {
            // Do nothing
        }
    }
    // Second child process for subtraction
    pid2 = fork();
    if (pid2 < 0) {
        perror("Failed to fork second child process");
        exit(1);
    }
    if (pid2 == 0) {
        printf("Child Process 2 (Subtraction): PID = %d, PPID = %d\n", getpid(), getppid());

        int difference = var1 - var2;
        printf("Subtraction: %d - %d = %d\n", var1, var2,

               difference);

        for (int i = 0; i < 1e10; i++) {
            // Do nothing
        }
    }

    // Third child process for multiplication
    pid3 = fork();
    if (pid3 < 0) {
        perror("Failed to fork third child process");
        exit(1);
    }

    if (pid3 == 0) {
        printf("Child Process 3 (Multiplication): PID = %d, PPID = %d\n", getpid(), getppid());
        int product = var1 * var2;
        printf("Multiplication: %d * %d = %d\n", var1, var2,

               product);

        for (int i = 0; i < 1e10; i++) {
            // Do nothing
        }
    }

    for (int i = 0; i < 1e10; i++) {
        // Do nothing
    }

    return 0;
}