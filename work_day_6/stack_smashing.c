#include <stdio.h>

void main() {
    char str[4];

    int length = sizeof(str);
    for (int i = 0; i < length + 3; i++) {
        str[i] = '*';
        printf("%s\n", str);
    }
}
