#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signalHandler(int signalNo) {
    printf("received signal no: %d\n", signalNo);
}
int main() {
    signal(SIGHUP, signalHandler);
    printf("waiting...\n");
    sleep(99999);

    return 0;
}