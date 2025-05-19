//Write C program that takes a binary number (as an integer) as input and converts it to its decimal equivalent.

#include<stdio.h>

int main() {
    int binary, decimal = 0, i = 0, remainder;

    printf("Enter a binary number: ");
    scanf("%d", &binary);

    while(binary != 0) {
        remainder = binary % 10;
        decimal += remainder * (1 << i);  // Using bitwise shift to calculate powers of 2
        binary /= 10;
        i++;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}

