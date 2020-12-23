#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct MQ
{
    long type;
    char str[100];
} mq;

int main()
{
    key_t key;
    int msgid;

    key = 1234;

    msgid = msgget(key, 0666 | IPC_CREAT);
    mq.type = 1;

    printf("Enter a string : ");
    scanf("%s", mq.str);

    msgsnd(msgid, &mq, sizeof(mq), 0);
    return 0;
}