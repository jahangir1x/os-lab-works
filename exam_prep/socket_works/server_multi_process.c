// forked_server.c
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "Hello from forked server";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Forked server is waiting for connections...\n");
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) >= 0) {
        pid_t pid = fork();
        if (pid == 0) {        // Child process
            close(server_fd);  // Close server socket in child
            read(new_socket, buffer, 1024);
            printf("Client: %s\n", buffer);
            send(new_socket, message, strlen(message), 0);
            close(new_socket);
            exit(0);
        } else if (pid > 0) {   // Parent process
            close(new_socket);  // Close client socket in parent
        } else {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        waitpid(-1, NULL, WNOHANG);  // Clean up any finished child processes
    }

    return 0;
}
