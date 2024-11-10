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



```
