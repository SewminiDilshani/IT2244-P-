// receiver.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 100

// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[MAX];
} message;

int main() {
    key_t key;
    int msgid;
    int pid;

    // Ask the user for their sender's PID
    printf("Enter your sender's PID to receive your own message: ");
    scanf("%d", &pid);

    // ftok to generate unique key
    key = ftok("progfile", 65);

    // msgget creates message queue
    msgid = msgget(key, 0666 | IPC_CREAT);

    // msgrcv to receive message with specific PID type
    msgrcv(msgid, &message, sizeof(message), pid, 0);

    // display the message
    printf("Data received is: %s\n", message.mesg_text);

    return 0;
}
