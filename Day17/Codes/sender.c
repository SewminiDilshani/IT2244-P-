// sender.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h> // for getpid()
#define MAX 100

// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[MAX];
} message;

int main() {
    key_t key;
    int msgid;

    // ftok to generate unique key
    key = ftok("progfile", 65);

    // msgget creates a message queue and returns identifier
    msgid = msgget(key, 0666 | IPC_CREAT);

    // Set message type to current process ID (unique per user)
    message.mesg_type = getpid();

    printf("Write Data to Send: ");
    fgets(message.mesg_text, MAX, stdin);

    // msgsnd to send message
    msgsnd(msgid, &message, sizeof(message), 0);

    // Display the message
    printf("Data sent is: %s\n", message.mesg_text);
    printf("Use PID: %d in receiver to get your message.\n", getpid());

    return 0;
}
