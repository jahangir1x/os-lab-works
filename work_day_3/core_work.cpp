#include "headers.h"
int main() {
    int coreNo, priority;

    coreNo = sched_getcpu();
    priority = getpriority(PRIO_PROCESS, 0);
    printf("Logical processor: %d, Niceness: %d\n", coreNo, priority);

    // setpriority(PRIO_PROCESS, 0, 10);
    // priority = getpriority(PRIO_PROCESS, 0);
    // printf("Logical processor: %d, Niceness: %d\n", coreNo, priority);
    // sleep(1);

    // setpriority(PRIO_PROCESS, 0, 17);
    // priority = getpriority(PRIO_PROCESS, 0);
    // printf("Logical processor: %d, Niceness: %d\n", coreNo, priority);

    // nice(2);
    // priority = getpriority(PRIO_PROCESS, 0);
    // printf("Logical processor: %d, Niceness: %d\n", coreNo, priority);
    sleep(9999);

    return 0;
}