#include "headers.h"

char *sharedMemoryName = "/sum_shared";
int *sharedMemory;

int sum()
{
    *sharedMemory = *sharedMemory + 1;
    printf("After summaion: %d\n", *sharedMemory);
}

int main()
{
    int shmFd = shm_open(sharedMemoryName, O_CREAT | O_RDWR, 0666);
    sharedMemory = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmFd, 0);

    ftruncate(shmFd, sizeof(int));

    *sharedMemory = 0;

    sum();
    sum();
    sum();
    sum();
    sum();
    sum();

    sleep(3);

    munmap(sharedMemory, sizeof(int));
    shm_unlink(sharedMemoryName);
}
