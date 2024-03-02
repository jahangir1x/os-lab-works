#include "headers.h"

int main() {
    int fd = open("./pipe", O_RDONLY);

    if (fd == -1) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    read(fd, buffer, sizeof(buffer));

    close(fd);

    write(STDOUT_FILENO, buffer, strlen(buffer));

    return 0;
}
