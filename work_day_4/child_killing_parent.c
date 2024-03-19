#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid_t parentPid = getpid();
    pid = fork();

    if (pid == 0) {
        printf("in child");
        sleep(4);
        kill(parentPid, 9);
        sleep(3);
    } else {
        printf("in parent\n");
        for (int i = 0; i < 1e10; i++) {
            printf("running %d\n", i);
        }
    }

    return 0;
}