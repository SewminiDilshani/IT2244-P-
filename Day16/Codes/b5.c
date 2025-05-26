/* Ex:
The parent creates a child process.
The child creates a grandchild process.
The grandchild sleeps 2 seconds and exits with status 2.
The child waits for the grandchild, prints its exit status, 
then exits with status 55.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid_child, pid_grandchild;
    int status;

    pid_child = fork();  // Parent creates child
    if (pid_child < 0) {
        perror("fork failed");
        exit(1);
    }

    if (pid_child == 0) {
        // Child process
        pid_grandchild = fork();  // Child creates grandchild

        if (pid_grandchild < 0) {
            perror("fork failed");
            exit(1);
        }

        if (pid_grandchild == 0) {
            // Grandchild process
            sleep(2);
            exit(2);
        } else {
            // Child waits for grandchild
            waitpid(pid_grandchild, &status, 0);
            if (WIFEXITED(status)) {
                printf("Child: Grandchild exited with status %d\n", WEXITSTATUS(status));
            } else {
                printf("Child: Grandchild did not exit normally\n");
            }
            // Child exits with status 55
            exit(55);
        }
    } else {
        // Parent waits for child to finish
        waitpid(pid_child, &status, 0);
        if (WIFEXITED(status)) {
            printf("Parent: Child exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: Child did not exit normally\n");
        }
    }

    return 0;
}
