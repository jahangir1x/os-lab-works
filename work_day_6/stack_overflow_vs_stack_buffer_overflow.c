#include <stdio.h>

void stack_overflow(int x) {
    stack_overflow(x + 1);
}

void stack_buffer_overflow() {
    char buffer[4];
    for (int i = 0; i < 10; i++) {
        buffer[i] = 'x';
    }
}

int main() {
    // stack_overflow(0);
    stack_buffer_overflow();
    return 0;
}