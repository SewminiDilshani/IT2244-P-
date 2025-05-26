/* Ex:
First child: Sleeps for 2 seconds, exits with status 2.
Second child: Sleeps for 1 second, exits with status 1.
Parent: Waits twice, and prints which child(by PID or exit code) finished first and second.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    pid_t first_finished, second_finished;
    int status;
    
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        exit(1);
    }
    if (pid1 == 0) {
        // First child: sleeps 2 seconds, exit status 2
        sleep(2);
        exit(2);
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        exit(1);
    }
    if (pid2 == 0) {
        // Second child: sleeps 1 second, exit status 1
        sleep(1);
        exit(1);
    }

    // Parent: wait for both children, detect order of completion
    first_finished = wait(&status);
    if (WIFEXITED(status)) {
        printf("Parent: Child with PID %d finished first, exit status %d.\n",
               first_finished, WEXITSTATUS(status));
    } else {
        printf("Parent: Child with PID %d did not exit normally.\n", first_finished);
    }

    second_finished = wait(&status);
    if (WIFEXITED(status)) {
        printf("Parent: Child with PID %d finished second, exit status %d.\n",
               second_finished, WEXITSTATUS(status));
    } else {
        printf("Parent: Child with PID %d did not exit normally.\n", second_finished);
    }

    return 0;
}
