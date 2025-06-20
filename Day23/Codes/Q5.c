5]
Implement a thread function that takes an integer argument, squares it and returns the result to the main
thread using pthread_exit and pthread_join.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int));
    *result = num * num;
    pthread_exit(result);
}

int main() {
    pthread_t t;
    int num = 7;  // example input
    int* res;

    pthread_create(&t, NULL, square, &num);
    pthread_join(t, (void**)&res);

    printf("Square of %d is %d\n", num, *res);
    free(res);
    return 0;
}
