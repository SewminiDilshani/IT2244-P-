#include<stdio.h>                          // Include the standard I/O library
int main() {

    // Working with double
    double number = 12.45;                // Declare a double variable and assign value 12.45
    printf("%lf\n", number);              // Print the double value with default format
    printf("%.2lf\n", number);            // Print the double value with 2 decimal places

    // Working with float
    float number1 = 10.9f;                // Declare a float variable and assign value 10.9 (use 'f' for float literal)
    printf("%f\n", number1);              // Print the float value with default format (6 decimal places)
    printf("%.1f\n", number1);            // Print the float value with 1 decimal place

    // Working with char
    char character = 'z';                 // Declare a char variable and assign character 'z'
    printf("%c\n", character);            // Print the character itself
    printf("%d\n", character);            // Print the ASCII value of the character

    return 0;                             // Return 0 to indicate successful program execution
}
