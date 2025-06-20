4]
Create two threads where one thread increments a global counter 100 times and the other thread decrements the same
counter 100 times.Print the final value of the counter after both threads finish.

#include <stdio.h>
#include <pthread.h>

int counter = 0;

void* increment(void* arg) {
    for (int i = 0; i < 100; i++) {
        counter++;
    }
    return NULL;
}

void* decrement(void* arg) {
    for (int i = 0; i < 100; i++) {
        counter--;
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, decrement, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value: %d\n", counter);
    return 0;
}
