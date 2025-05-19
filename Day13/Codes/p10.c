//Write a C program to calculate the factorial of a given non-negative integer.

#include <stdio.h>

int main() {
    int num;
    unsigned long long factorial = 1;  // To store the result of factorial

    // Ask the user to enter a number
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Check if the number is negative
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // Calculate factorial using a loop
        for (int i = 1; i <= num; i++) {
            factorial *= i;  // Multiply factorial by i in each iteration
        }
        // Display the result
        printf("Factorial of %d is %llu\n", num, factorial);
    }

    return 0;
}
