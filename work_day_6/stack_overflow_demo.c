#include <stdio.h>
#include <string.h>

void overflowDemoFunction(char *inputStr) {
    char buffer1[4] = "xyz";
    char buffer2[4] = "zyx";

    printf("before buffer1: %s\n", buffer1);
    printf("before buffer2: %s\n", buffer2);

    strcpy(buffer1, inputStr);

    printf("after buffer1: %s\n", buffer1);
    printf("after buffer2: %s\n", buffer2);
}

int main() {
    char *str = "abcdefghijklmnopqralskdjfksdjflksjfklsdjf";
    overflowDemoFunction(str);

    printf("ending main...\n");
    return 0;
}
