#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    char *msg;
    char buffer[100];

    int n, c;

    msg = "Insert a number: ";
    write(STDOUT_FILENO, msg, strlen(msg));

    n = read(STDIN_FILENO, &buffer, sizeof(buffer));

    buffer[n] = '\0';

    write(STDOUT_FILENO, buffer, strlen(buffer));
}