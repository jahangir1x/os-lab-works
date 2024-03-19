#include <fcntl.h>
#include <stdio.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid == 0) {
        printf("in child");
        for (int i = 0; i < 1e10; i++) {
            printf("running %d\n", i);
        }
    } else {
        printf("in parent\n");
        sleep(4);
        kill(pid, 9);
        printf("killed child\n");
        sleep(5);
    }

    return 0;
}