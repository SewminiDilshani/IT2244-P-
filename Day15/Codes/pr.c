#include <stdio.h>
#include <unistd.h>

void factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {  
        fact *= i;
    }
    printf("Factorial of %d is: %d\n", n, fact);
}

void fibonacci(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci series up to %d: \n", n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", a);  
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

void check_prime(int n) {
    int flag = 1;
    if (n < 2) flag = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
    printf("%d is %s prime\n", n, flag ? "" : "not ");
}

int main() {
    int A, B, C;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &A, &B, &C);

    pid_t child1, child2;
    child1 = fork();

    if (child1 == 0) {
        factorial(A);
    } else {
        child2 = fork();
        if (child2 == 0) {
            pid_t childB, childC;
            childB = fork();
            if (childB == 0) {
                fibonacci(B);
            } else {
                childC = fork();
                if (childC == 0) {
                    check_prime(C);
                }
            }
        }
    }

    return 0;
}
