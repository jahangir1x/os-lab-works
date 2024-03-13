#include "headers.h"

char *sharedMemoryName = "/sum_shared";
char *semaphoreName = "/semaphore_sum_2";
int *sharedMemory;
sem_t *sem;
int sum()
{
    for (int i = 0; i < 10000000; i++)
    {
        sem_wait(sem);
        *sharedMemory = *sharedMemory + 1;
        printf("After summaion: %d\n", *sharedMemory);
        sem_post(sem);
    }
}

int main()
{
    int shmFd = shm_open(sharedMemoryName, O_CREAT | O_RDWR, 0666);
    sharedMemory = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmFd, 0);

    ftruncate(shmFd, sizeof(int));

    sem = sem_open(semaphoreName, O_CREAT | O_EXCL, 0666, 1);

    *sharedMemory = 0;

    sum();

    sem_close(sem);
    sem_unlink(semaphoreName);

    munmap(sharedMemory, sizeof(int));
    shm_unlink(sharedMemoryName);
}
