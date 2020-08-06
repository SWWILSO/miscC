#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSGSIZE 255

typedef struct {
    long mtype;
    char msg[MSGSIZE];
} msg_t;

int main() {
    int msqid, msglen;
    key_t key;
    msg_t msgbuff;
    system("touch messagefile");

    if ((key = ftok("messagefile", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }
    if ((msqid = msgget(key, 066 | IPC_CREAT)) == -1) {
        perror("msgget");
        exit(1);
    }

    msgbuff.mtype = 1;
    printf("Enter a message to add to queue:\n>> ");
    scanf("%s", msgbuff.msg);
    msglen = strlen(msgbuff.msg);

    if (msgsnd(msqid, &msgbuff, msglen, IPC_NOWAIT) > 0) {
        perror("msgsend");
    }

    printf("The message sent is '%s'\n", msgbuff.msg);
    return 0;
}