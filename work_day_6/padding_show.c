#include <stdio.h>

int main() {
    char buffer[8];
    int x;
    float y;
    printf("address of buffer: %p\n", buffer);
    printf("address of x: %p\n", &x);
    printf("address of y: %p\n", &y);
    printf("ending main...\n");
    return 0;
}