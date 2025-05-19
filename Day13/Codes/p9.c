//C program to generate Pascal's Triangle.
No of rows =5
          1
        1   1
      1   2   1
    1   3   3   1
  1   4   6   4   1


#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// Function to calculate binomial coefficient
int binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int rows = 5;

    for(int i = 0; i < rows; i++) {
        // Print spaces for alignment
        for(int space = 0; space < rows - i - 1; space++) {
            printf("  ");
        }

        // Print values in the row
        for(int j = 0; j <= i; j++) {
            printf("%4d", binomialCoeff(i, j));
        }

        printf("\n");
    }

    return 0;
}

