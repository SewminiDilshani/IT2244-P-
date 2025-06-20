2]
Write a program to create 5 threads.Each thread should print its thread ID and then exit.The main thread should
join all threads and print a completion message.

#include <stdio.h>
#include <pthread.h>

void* print_thread_id(void* arg) {
    pthread_t tid = pthread_self();
    printf("Thread ID: %lu\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[5];

    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, print_thread_id, NULL);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");
    return 0;
}
