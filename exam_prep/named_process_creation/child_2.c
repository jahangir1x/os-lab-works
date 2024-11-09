#include "../../headers.h"

int main() {
    printf("Child 2 Process: %d, Parent: %d\n", getpid(), getppid());
    return 0;
}