Exercise-:
IPC using Message Queue
read inputs from the parent process
Enter Name: hi
Enter RegNo: 2314
Enter Age: 24

Message sent successfully.

Give the output from the child process

Received Name: hi
Received RegNo: 2314
Received Age: 24
------------------------------------------------------------------------------------------------------------------


#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGKEY 1111
#define MAX_NAME_LEN 100
#define MAX_REGNO_LEN 100

struct person {
    long mtype; // Message type
    int age;
    char name[MAX_NAME_LEN];
    char regno[MAX_REGNO_LEN];
};

int main() {
    int msqid;
    struct person p1, p2;
    int f = fork();

    if (f == 0) {
        // Child process: Receiver
        msqid = msgget(MSGKEY, IPC_CREAT | 0666); 
        if (msqid == -1) {
            perror("msgget failed");
            exit(EXIT_FAILURE);
        }

        int msg_size = sizeof(struct person) - sizeof(long);

        if (msgrcv(msqid, &p2, msg_size, 0, 0) == -1) {
            perror("msgrcv failed");
            exit(EXIT_FAILURE);
        } else {
            printf("Received Name: %s\n", p2.name);
            printf("Received RegNo: %s\n", p2.regno);
            printf("Received Age: %d\n", p2.age);
        }

        if (msgctl(msqid, IPC_RMID, NULL) == -1) {
            perror("msgctl failed");
            exit(EXIT_FAILURE);
        }
    } else {
        // Parent process: Sender
        msqid = msgget(MSGKEY, IPC_CREAT | 0666);
        if (msqid == -1) {
            perror("msgget failed");
            exit(EXIT_FAILURE);
        }

        p1.mtype = 1;

        printf("Enter Name: ");
        scanf("%s", p1.name);

        printf("Enter RegNo: ");
        scanf("%s", p1.regno);

        printf("Enter Age: ");
        scanf("%d", &p1.age);

        int msg_size = sizeof(struct person) - sizeof(long);

        if (msgsnd(msqid, &p1, msg_size, IPC_NOWAIT) == -1) {
            perror("msgsnd failed");
        } else {
            printf("Message sent successfully.\n");
        }

        exit(0);
    }

    return 0;
}
