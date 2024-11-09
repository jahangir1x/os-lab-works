#include "../../headers.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <number_of_children> <child_1> <child_2> ... <child_n>\n", argv[0]);
        exit(1);
    }
    int n = atoi(argv[1]);

    if (argc != n + 2) {
        fprintf(stderr, "Error: Number of child names provided does not match the number of children specified.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }

        if (pid == 0) {
            prctl(PR_SET_NAME, argv[i + 2], 0, 0, 0);
            printf("Child process %s with PID %d started\n", argv[i + 2], getpid());

            sleep(1);
            printf("Child process %s with PID %d finished\n", argv[i + 2], getpid());
            exit(0);
        }
    }

    sleep(9999);
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }
    printf("Parent process (PID: %d) finished\n", getpid());
    return 0;
}
