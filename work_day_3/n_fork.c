#include "headers.h"

int childPID;

int main() {
    for (int i = 0; i < 5; i++) {
        childPID = fork();
    }

    if (childPID == 0) {
        printf("running for %d\n", childPID);
    }

    sleep(10000);

    return 0;
}