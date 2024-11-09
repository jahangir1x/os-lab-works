#include "../../headers.h"

int main() {
    printf("Child 1 Process: %d, Parent: %d\n", getpid(), getppid());
    return 0;
}