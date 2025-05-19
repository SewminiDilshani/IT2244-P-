//Give list of numbers then calculate the summation and multiplication using for loop.

#include <stdio.h>

int main() {
    int n, num;
    int sum = 0;
    int product = 1;

    printf("Enter how many numbers: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;         // Add to sum
        product *= num;     // Multiply for product
    }

    printf("Summation = %d\n", sum);
    printf("Multiplication = %d\n", product);

    return 0;
}
