#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

char *sharedMemoryName = "/sum_shared";

int main() {
    // Open the shared memory object
    int shmFd = shm_open(sharedMemoryName, O_RDONLY, 0666);

    int *sharedMemory = (int *)mmap(NULL, sizeof(int), PROT_READ, MAP_SHARED, shmFd, 0);
    printf("Read from shared memory: %d\n", *sharedMemory);

    munmap(sharedMemory, sizeof(int));

    return 0;
}
