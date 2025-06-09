/*
Area Calculation Program
Circle => C
Triangle => T
Square => S 
Rectangle => R 
Enter your choice: C

Circle Area Calculation
Enter the radius: 20.9
Area is: 1371.58
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

int main() {
    char choice;
    float input1, input2;

    printf("\nArea Calculation Program\n");
    printf("Circle => C\nTriangle => T\nSquare => S\nRectangle => R\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice); // Note the space before %c

    pid_t pid = fork();  // create child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process handles calculation
        switch (choice) {
            case 'C':
            case 'c':
                printf("\nCircle Area Calculation\n");
                printf("Enter the radius: ");
                scanf("%f", &input1);
                printf("Area is: %.2f\n", M_PI * input1 * input1);
                break;

            case 'T':
            case 't':
                printf("\nTriangle Area Calculation\n");
                printf("Enter base and height: ");
                scanf("%f %f", &input1, &input2);
                printf("Area is: %.2f\n", 0.5 * input1 * input2);
                break;

            case 'S':
            case 's':
                printf("\nSquare Area Calculation\n");
                printf("Enter the side: ");
                scanf("%f", &input1);
                printf("Area is: %.2f\n", input1 * input1);
                break;

            case 'R':
            case 'r':
                printf("\nRectangle Area Calculation\n");
                printf("Enter length and width: ");
                scanf("%f %f", &input1, &input2);
                printf("Area is: %.2f\n", input1 * input2);
                break;

            default:
                printf("Invalid choice.\n");
        }
    } 
    else {
        // Parent process waits for child
        wait(NULL);
        printf("Calculation completed by child process.\n");
    }

    return 0;
}

