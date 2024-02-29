#include "headers.h"

void createPipe() {
    if (access("./chatPipe", F_OK) == 0) {
        printf("using previous chat pipe...\n\n");
    } else {
        int pipeFlag = mkfifo("./chatPipe", 0666);
        printf("created chat pipe\n\n");
    }
}

void writeToPipe() {
    write(STDOUT_FILENO, "Client 1: ", 10);
    char buffer[1024];
    int dataReadCount = read(STDIN_FILENO, &buffer, sizeof(buffer));
    buffer[dataReadCount] = '\0';
    int fd = open("./chatPipe", O_WRONLY);
    write(fd, buffer, dataReadCount);
    close(fd);
    if (strncmp(buffer, "bye\n", 4) == 0) {
        exit(EXIT_SUCCESS);
    }
}

void readFromPipe() {
    int fd = open("./chatPipe", O_RDONLY);
    if (fd == -1) {
        printf("Error opening pipe");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int bytesRead = read(fd, buffer, sizeof(buffer));
    close(fd);
    write(STDOUT_FILENO, "Client 2: ", 10);
    write(STDOUT_FILENO, buffer, bytesRead);

    return;
}

int main() {
    createPipe();
    while (1) {
        writeToPipe();
        readFromPipe();
    }
    return 0;
}
