#include <stdio.h>            // Includes the standard input/output library for printf
int main() {                  // Main function: program execution starts here
    printf("Hello World\n");  // Prints "Hello World" followed by a new line
    return 0;                 // Returns 0 to indicate successful program completion
}





# Open vi editor to create/edit the file
# (Write the code above inside vi and save it)
[2021ict114@fedora ~]$ vi pr1.c  
# Compiles the pr1.c file using gcc.
# -o pr1 tells the compiler to output an executable named pr1.              
[2021ict114@fedora ~]$ gcc pr1.c -o pr1        
# Run the compiled program
[2021ict114@fedora ~]$ ./pr1                   
Hello World                                     
