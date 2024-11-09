#include "../../headers.h"

char const *fifo = "ipc_fifo";

int main() {
    // mkfifo (fifo, 0666);
    int fd = open(fifo, O_WRONLY);

    while (1) {
        char input[128];
        printf("Enter a number or BYE: ");
        scanf("%s", input);
        write(fd, input, strlen(input)+1);
        if (strcmp(input, "BYE") == 0) {
            break;
        }
    }

    close(fd);
    // unlink(fifo);
    return 0;
}