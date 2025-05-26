/*  Ex:
First child: Slept for 1 seconds.
Second child: Slept for 3 seconds.
Parent: Both children have finished.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    
    printf("Parent process started. PID: %d\n", getpid());
    
    pid1 = fork();  // Create first child
    
    if (pid1 < 0) {
        perror("Fork failed");
        exit(1);
    }
    
    if (pid1 == 0) {
        // First child process
        printf("First child: Slept for 1 seconds.\n");
        sleep(1);
        printf("First child exiting.\n");
        exit(0);
    } else {
        // Parent creates second child
        pid2 = fork();
        if (pid2 < 0) {
            perror("Fork failed");
            exit(1);
        }
        
        if (pid2 == 0) {
            // Second child process
            printf("Second child: Slept for 3 seconds.\n");
            sleep(3);
            printf("Second child exiting.\n");
            exit(0);
        } else {
            // Parent process
            int status;
            printf("Parent waiting for both children to finish...\n");
            
            // Wait for first child
            waitpid(pid1, &status, 0);
            if (WIFEXITED(status)) {
                printf("First child exited with status: %d\n", WEXITSTATUS(status));
            } else {
                printf("First child did not exit normally.\n");
            }
            
            // Wait for second child
            waitpid(pid2, &status, 0);
            if (WIFEXITED(status)) {
                printf("Second child exited with status: %d\n", WEXITSTATUS(status));
            } else {
                printf("Second child did not exit normally.\n");
            }
            
            printf("Parent: Both children have finished.\n");
        }
    }
    
    return 0;
}
