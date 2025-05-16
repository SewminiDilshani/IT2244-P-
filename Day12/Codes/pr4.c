#include<stdio.h>                          // Includes the standard input/output library
int main() {
    int age = 25;                          // Declare and initialize an integer variable 'age' with value 25
    printf("%d\n", age);                   // Print the value of 'age'
    // Print the size (in bytes) of the 'age' variable using sizeof
    printf("Size: %zu\n", sizeof(age));    // %zu is the format specifier for size_t
    return 0;                              // Return 0 to indicate successful execution
}
