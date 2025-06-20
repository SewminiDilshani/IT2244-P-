3]
Write a program that creates a thread which prints numbers from 1 to 10 with a 1 second delay between each number.
The main thread should wait for this thread to finish.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* print_numbers(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t t;

    pthread_create(&t, NULL, print_numbers, NULL);
    pthread_join(t, NULL);

    printf("Number printing thread finished.\n");
    return 0;
}
