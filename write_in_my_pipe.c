#include "headers.h"

int main() {
    int fd = open("./pipe", O_WRONLY);
    if (fd == -1) {
        perror("Error opening named pipe for writing");
        exit(EXIT_FAILURE);
    }

    char* write_data = "something very cool";

    // Write data to the pipe
    if (write(fd, write_data, strlen(write_data)) == -1) {
        perror("Error writing to named pipe");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Data written to the pipe successfully.\n");

    // Close pipe
    close(fd);
}