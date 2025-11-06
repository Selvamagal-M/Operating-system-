
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>   // for sleep()

#define NUM_PHILOSOPHERS 5

sem_t mutex;
sem_t forks[NUM_PHILOSOPHERS];

void* philosopher(void* num) {
    int phil = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking.\n", phil);
        sleep(1);

        // Try to pick up forks
        sem_wait(&mutex);
        sem_wait(&forks[phil]);
        sem_wait(&forks[(phil + 1) % NUM_PHILOSOPHERS]);
        sem_post(&mutex);

        printf("Philosopher %d is eating.\n", phil);
        sleep(2);

        // Put down forks
        sem_post(&forks[phil]);
        sem_post(&forks[(phil + 1) % NUM_PHILOSOPHERS]);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_PHILOSOPHERS];
    int philosopher_numbers[NUM_PHILOSOPHERS];

    sem_init(&mutex, 0, 1);
     int i;
    for ( i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    // Create threads
     
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_numbers[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &philosopher_numbers[i]);
    }

    // Join threads
     
    for ( i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
     
    for ( i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&forks[i]);
    }
    sem_destroy(&mutex);

    return 0;
}


