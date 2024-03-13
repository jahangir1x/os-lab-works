#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd;
    char data[] = "heeeee yeeeee!\n new line\n";

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd == -1) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    int bytesWritten = write(fd, data, sizeof(data));

    if (bytesWritten == -1) {
        printf("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Number of bytes written: %d\n", bytesWritten);

    close(fd);

    return 0;
}
