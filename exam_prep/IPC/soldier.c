#include "../../headers.h"

char *fifo = "ipc_fifo";

int main() {
    int fd = open(fifo, O_RDONLY);

    while (1) {
        char input[128];
        read(fd, input, sizeof(input));

        if (strcmp(input, "BYE") == 0) {
            printf("Received BYE\n");
            break;
        }

        int n = atoi(input);
        printf("Received: %d\n", n);
        for (int i = n; i > 0; i--) {
            printf("%d\n", i);
            sleep(1);
        }
    }

    close(fd);
    return 0;
}