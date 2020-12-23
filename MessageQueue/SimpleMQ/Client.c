#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

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

    msgrcv(msgid, &mq, sizeof(mq), 1, 0);

    printf("Data Received is : %s \n", mq.message);
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}