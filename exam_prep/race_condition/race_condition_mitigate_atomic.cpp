#include <bits/stdc++.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <atomic>

using namespace std;

atomic_int shared_counter;

void* increment_counter(void* arg) {
    for (int i = 0; i < 1e8; i++) {
        shared_counter++;
    }
    return NULL;
}

void* decrement_counter(void* arg) {
    for (int i = 0; i < 1e8; i++) {
        shared_counter--;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, decrement_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    cout << "shared: " << shared_counter << endl;

    return 0;
}
