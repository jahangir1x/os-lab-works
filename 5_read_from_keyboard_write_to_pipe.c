#include "headers.h"

int main() {
    char* msg = "Insert something: ";
    write(STDOUT_FILENO, msg, strlen(msg));

    char write_data[100];
    int totalDataRead = read(STDIN_FILENO, &write_data, sizeof(write_data));
    write_data[totalDataRead] = '\0';

    int fd = open("./pipe", O_WRONLY);
    if (fd == -1) {
        printf("Error opening named pipe for writing");
        exit(EXIT_FAILURE);
    }

    write(fd, write_data, strlen(write_data));

    printf("Data written to the pipe successfully.\n");

    close(fd);
}