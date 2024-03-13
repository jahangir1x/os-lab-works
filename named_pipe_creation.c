#include "headers.h"

int main() {
    int pipeFlag, fd;
    char *pipePath = "./pipe";
    if (access(pipePath, F_OK) == 0) {
        printf("%s is created\n", pipePath);
    } else {
        pipeFlag = mkfifo(pipePath, 0666);

        if (pipeFlag < 0) {
            printf("Error in creating\n");
            exit(-1);
        } else {
            printf("pipe created successfully\n");
        }
    }
}