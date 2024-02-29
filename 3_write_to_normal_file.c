#include "headers.h"

int main() {
    int fd;
    char data[] = "something something!\nVery fun\n";

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (fd == -1) {
        printf("Error opening file");
        exit(EXIT_FAILURE);
    }

    write(fd, data, sizeof(data));

    close(fd);

    return 0;
}
