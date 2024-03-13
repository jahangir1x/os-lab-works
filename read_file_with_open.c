#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[1024];

    fd = open("example.txt", O_RDONLY);

    if (fd == -1) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    int bytesRead = read(fd, buffer, sizeof(buffer));

    if (bytesRead == -1) {
        printf("Error reading from file");
        close(fd);
        exit(1);
    }

    printf("Content of the file:\n%s\n", buffer);

    close(fd);

    return 0;
}
