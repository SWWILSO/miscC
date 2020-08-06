#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 255

typedef struct {
    long mtype;
    char msg[MSGSIZE];
} msg_t;

int main() {
    int msqid;
    key_t key;
    msg_t rcvbuff;
    system("touch messagefile");

    if ((key = ftok("messagefile", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }
    if ((msqid = msgget(key, 0666)) < 0) {
        perror("msgget");
        exit(1);
    }

    if (msgrcv(msqid, &rcvbuff, MSGSIZE, 1, 0) < 0) {
        perror("msgrcv");
        exit(1);
    }
    printf("The message received is '%s'\n", rcvbuff.msg);
    return 0;
}