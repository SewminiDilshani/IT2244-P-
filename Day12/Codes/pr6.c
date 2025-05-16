#include<stdio.h>                          // Includes the standard input/output functions
int main() {
    int age;                               // Declare an integer variable to store the user's age
    printf("Enter your age:");             // Prompt the user to enter their age
    scanf("%d", &age);                     // Read an integer input from the user and store it in 'age'
                                           // '&age' gives the address of the variable to store the input
    printf("Age = %d\n", age);             // Print the age entered by the user
    return 0;                              // Return 0 to indicate successful execution
}
