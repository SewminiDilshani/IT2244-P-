#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>  // Include this header for wait()

#define MSGSIZE 256  // Increase the message size for proper storage of strings

int main() {
    int p[2];  // Pipe file descriptors
    pid_t pid;
    
    // Declare char pointers
    char *name;
    char *regno;
    char *age;
    
    // Create a pipe
    if (pipe(p) < 0) {
        perror("Pipe failed");
        exit(1);
    }

    // Allocate memory for the strings using malloc()
    name = (char *)malloc(MSGSIZE * sizeof(char));
    regno = (char *)malloc(MSGSIZE * sizeof(char));
    age = (char *)malloc(MSGSIZE * sizeof(char));
    
    if (name == NULL || regno == NULL || age == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    // Input data from the parent process
    printf("Enter name: ");
    fgets(name, MSGSIZE, stdin);
    name[strcspn(name, "\n")] = 0;  // Remove the newline character

    printf("Enter registration number: ");
    fgets(regno, MSGSIZE, stdin);
    regno[strcspn(regno, "\n")] = 0;  // Remove the newline character

    printf("Enter age: ");
    fgets(age, MSGSIZE, stdin);
    age[strcspn(age, "\n")] = 0;  // Remove the newline character

    // Create a child process using fork()
    if ((pid = fork()) < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {  // Parent process
        // Close the reading end of the pipe
        close(p[0]);
        
        // Write to the pipe using pointers
        write(p[1], name, MSGSIZE);
        write(p[1], regno, MSGSIZE);
        write(p[1], age, MSGSIZE);

        // Close the writing end of the pipe
        close(p[1]);

        // Wait for the child process to finish
        wait(NULL);
    } else {  // Child process
        // Close the writing end of the pipe
        close(p[1]);

        // Read from the pipe and print the received information using pointers
        char buffer[MSGSIZE];
        
        read(p[0], buffer, MSGSIZE);
        printf("Name: %s\n", buffer);

        read(p[0], buffer, MSGSIZE);
        printf("Reg. No: %s\n", buffer);

        read(p[0], buffer, MSGSIZE);
        printf("Age: %s\n", buffer);

        // Close the reading end of the pipe
        close(p[0]);
    }

    // Free allocated memory
    free(name);
    free(regno);
    free(age);

    return 0;
}
