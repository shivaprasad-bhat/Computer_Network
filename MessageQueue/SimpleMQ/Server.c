#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct MQ
{
    long type;
    char message[100];
} mq;

int main()
{
    key_t key;
    int msgid;

    key = 1234;

    msgid = msgget(key, 0666 | IPC_CREAT);
    mq.type = 1;

    printf("Enter the message : ");
    fgets(mq.message, 100, stdin);

    msgsnd(msgid, &mq, sizeof(mq), 0);

    printf("Data sent : %s\n", mq.message);

    return 0;
}