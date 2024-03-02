#include "headers.h"

int main() {
    int fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[200];
    int bytesRead = read(fd, &buffer, sizeof(buffer));
    buffer[bytesRead] = '\0';

    write(STDOUT_FILENO, buffer, strlen(buffer));
}