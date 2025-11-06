
#include <stdio.h>
#include <pthread.h>

int shared = 0;
pthread_mutex_t lock;

void* thread_func(void* arg) {
    pthread_mutex_lock(&lock);

    int val = shared;
    printf("Thread %ld: read shared = %d\n", (long)arg, val);
    val += 1;
    shared = val;
    printf("Thread %ld: updated shared = %d\n", (long)arg, shared);

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, thread_func, (void*)1);
    pthread_create(&t2, NULL, thread_func, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("Final value of shared = %d\n", shared);
    return 0;
}

