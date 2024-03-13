#include <stdio.h>
#include <unistd.h>
void main() {
    execlp("./child", NULL);
}