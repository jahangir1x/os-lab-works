#include "headers.h"

int main() {
    char *msg;
    char buffer[100];

    int n, c;

    msg = "Insert something: ";
    write(STDOUT_FILENO, msg, strlen(msg));

    n = read(STDIN_FILENO, &buffer, sizeof(buffer));

    buffer[n] = '\0';

    write(STDOUT_FILENO, buffer, strlen(buffer));
}