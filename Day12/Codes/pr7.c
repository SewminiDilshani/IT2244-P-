#include<stdio.h>                            // Include standard input/output functions

int main() {
    double number;                           // Declare a double variable
    char alpha;                              // Declare a char variable

    printf("Enter double input:");           // Prompt user for a double number
    scanf("%lf", &number);                   // Read the double input
    printf("Your number is: %lf\n", number); // Print the entered double value

    printf("Enter character:");              
    scanf(" %c", &alpha);                    // Read a character input
    // Note: The space before %c skips any leftover newline or whitespace
    printf("Your character is: %c\n", alpha); // Print the entered character

    double number1;                          // Declare another double
    char alpha1;                             // Declare another char
    printf("Enter inputs:\n");
    scanf("%lf %c", &number1, &alpha1);      // Read both a double and a char in one line

    return 0;                                // End of program
}
