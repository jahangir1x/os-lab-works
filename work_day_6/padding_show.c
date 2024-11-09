#include <stdio.h>

int main() {
    char buffer[10];
    char x;
    float y;
    printf("address of buffer: \t%p\n", buffer);
    printf("address of x: \t\t%p\n", &x);
    printf("address of y: \t\t%p\n", &y);
    printf("ending main...\n");
    return 0;
}vvv