#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);  // Use &n to store the value at the address of n

    int child1 = fork();  // First fork

    if (child1 == 0) {
        // Child1 process
        printf("Child1 -> PID: %d \t PPID: %d\n", getpid(), getppid());

        // Factorial calculation
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        printf("Factorial of %d is %d\n", n, fact);

        // Child of child1 - for Fibonacci
        int child5 = fork();
        if (child5 == 0) {
            printf("Child5 -> PID: %d \t PPID: %d\n", getpid(), getppid());

            int a = 0, b = 1, fib = 0;
            for (int j = 1; j < n; j++) {
                fib = a + b;
                a = b;
                b = fib;
            }
            printf("Fibonacci term at position %d is %d\n", n, (n == 0) ? 0 : (n == 1) ? 1 : fib);
        } else {
            wait(NULL);  // Wait for child5
        }

    } else {
        // Parent process

        int child2 = fork();  // Second fork
        if (child2 == 0) {
            printf("Child2 -> PID: %d \t PPID: %d\n", getpid(), getppid());

            int s = 1;
            for (int k = 0; k < n; k++) {
                s *= 2;
            }
            printf("2 to the power of %d is %d\n", n, s);

        } else {
            int child3 = fork();  // Third fork
            if (child3 == 0) {
                printf("Child3 -> PID: %d \t PPID: %d\n", getpid(), getppid());
                int square = n * n;
                printf("Square of %d is %d\n", n, square);
            } else {
                // Parent waits for all its children
                wait(NULL);
                wait(NULL);
            }
        }
    }

    return 0;
}

