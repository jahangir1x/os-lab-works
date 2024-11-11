```c++
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <pthread.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/prctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>

// atomic variable ================
#include <atomic>
atomic_int shared_counter

// mutex ==========================
pthread_mutex_t lock;
pthread_mutex_init(&lock, NULL);
pthread_mutex_lock(&lock);
// do something
pthread_mutex_unlock(&lock);
pthread_mutex_destroy(&lock);

// semaphore ======================
#include <semaphore.h>
// wait() => decreases until it is zero
    // wait for an item to consume
// signal() => increases
    // signal that the item was produced
sem_t buffer_semaphore;
sem_post(&buffer_semaphore);
sem_wait(&buffer_semaphore);


// thread create ==================
void* thread_function(void* arg) {
    // do something
    return NULL;
}
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, thread_function, NULL);
pthread_join(thread1, NULL);

// pipe write =====================
char const *fifo_path = "fifo";
mkfifo(fifo_path, 0666);
int fd = open(fifo_path, O_WRONLY);
char const *str = "hello";
write(fd, str, strlen(str) + 1);
close(fd);

// pipe read ========================
int fd = open(fifo_path, O_RDONLY);
char input[128];
read(fd, input, sizeof(input));
close(fd);

unlink(fifo_path);

// rename process ===========
prctl(PR_SET_NAME, "process_name", 0, 0, 0);

// create process =============
execlp("./sample", NULL);

// system calls ==================
if (access("./file_path", F_OK) == 0) {
    // file exists
}
write(STDOUT_FILENO, "hello", 5+1);
char buffer[1024];
read(STDIN_FILENO, &buffer, sizeof(buffer));

// shared memory ================
char *shared_memory_name = "/sum_shared"
// write
int shm_fd = shm_open(shared_memory_name, O_CREAT | O_RDWR, 0666);
int* shared_memory = (int *) mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
    MAP_SHARED, shm_fd, 0);
ftruncate(shm_fd, sizeof(int));
*shared_memory = 100
// read
int shm_fd = shm_open(shared_memory_name, O_RDONLY, 0666);
int*  shared_memory = (int *) mmap(NULL, sizeof(int), PROT_READ,
    MAP_SHARED, shm_fd, 0);
cout << *shared_memory

munmap(shared_memory, sizeof(int));
shm_unlink(shared_memory_name);

// niceness and priority ============
// 0 -> 139 priority
// 0 -> 99 realtime : managed by kernel
// 100 -> 139 user_space (00 -> 39)
// PR = 00 : more priority
// PR = 39 : low priority
// NI = 19 low cpu (more nice)
// NI = -20 high cpu (less nice)
// PR = 20 + NI
int core_no = sched_getcpu();
int niceness = getpriority(PRIO_PROCESS, 0);
setpriority(PRIO_PROCESS, 0, 10);

// signal ===========================
// process
kill(pid, SIGUSR1)
// receiver
signal(SIGUSR1, signal_handler);
void signal_handler(int sig) {
    // received
}
// thread
pthread_t receiver_thread;
pthread_kill(receiver_thread, SIGUSR1);
// receive
signal(SIGUSR1, signal_handler);
void signal_handler(int sig) {
    // received
}


```
