#include <stdio.h>
#include <string.h>

void overflowDemoFunction(char *inputStr) {
    char buffer[4];
    strcpy(buffer, inputStr);
    printf("text copied: %s\n", buffer);
}

int main() {
    char *str = "abcdefghijklmnopqralskdjfksdjflksjfklsdjf";
    overflowDemoFunction(str);

    printf("ending main...\n");
    return 0;
}