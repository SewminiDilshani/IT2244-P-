#include<stdio.h>                  // Includes the standard input/output library
int main() {                       // Main function: where program execution begins
    int age = 25;                  // Declare an integer variable 'age' and initialize it to 25
    printf("%d\n", age);           // Print the value of 'age' (which is 25), followed by a new line
    printf("C programming");       // Print the text "C programming" (no new line at the end)
    age = 31;                      // Update the value of 'age' to 31
    printf("\nNew age:%d\n", age); // Print a new line, then "New age:31" with a new line
    return 0;                      // Return 0 to indicate successful program completion
}
