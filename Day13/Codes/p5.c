/*Write a C program to generate and print the Fibonacci series up to a specified number of terms.
The program should take the number of terms as input from the user and then display the 
corresponding Fibonacci sequence*/

#include<stdio.h>

int main() {
    int terms, first = 0, second = 1, next;

    // Ask the user for the number of terms in the Fibonacci sequence
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    // Print the title for the Fibonacci series
    printf("Fibonacci Series: ");

    // Loop through the number of terms
    for(int i = 1; i <= terms; i++) {
        // Print the first term, which is always 0
        if(i == 1) {
            printf("%d ", first);
            continue; // Skip to the next iteration
        }

        // Print the second term, which is always 1
        if(i == 2) {
            printf("%d ", second);
            continue; // Skip to the next iteration
        }

        // Calculate the next term in the sequence
        next = first + second;
        
        // Update first and second for the next iteration
        first = second;
        second = next;

        // Print the next term
        printf("%d ", next);
    }

    // Print a newline at the end of the sequence
    printf("\n");

    return 0;
}
