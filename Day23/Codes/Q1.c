1]
Write a C program that creates two threads.Each thread should print a message indicating it is running.
The main thread should wait for both threads to finish before exiting.

#include <stdio.h>    
#include <pthread.h>

void* thread_func(void* arg) {
    printf("Thread %ld is running\n", (long)arg);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_func, (void*)1);
    pthread_create(&t2, NULL, thread_func, (void*)2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads finished.\n");
    return 0;
}
