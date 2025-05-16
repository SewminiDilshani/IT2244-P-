#include<stdio.h>                              // Include the standard I/O functions

int main() {
    int n1;                                    // Declare first integer
    printf("Enter your number 1:");            // Prompt user for number 1
    scanf("%d", &n1);                          // Read number 1

    int n2;                                    // Declare second integer
    printf("Enter your number 2:");            // Prompt user for number 2
    scanf("%d", &n2);                          // Read number 2

    int result;                                // Declare result variable

    result = n1 + n2;                          // Addition
    printf("\nAddition: %d", result);

    result = n1 - n2;                          // Subtraction
    printf("\nSubtraction: %d", result);

    result = n1 * n2;                          // Multiplication
    printf("\nMultiplication: %d", result);

    result = n1 / n2;                          // Division (integer division)
    printf("\nDivision: %d", result);

    result = n1 % n2;                          // Modulus (remainder)
    printf("\nModulus: %d\n", result);

    return 0;                                  // End of program
}
