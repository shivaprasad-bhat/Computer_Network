#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

struct MQ
{
    long type;
    char op;
    int r, x, y;
};

int main()
{
    struct MQ req;
    key_t key;
    int msgid;

    key = 1234;

    msgid = msgget(key, 0666 | IPC_CREAT);
    req.type = 1;

    printf("Enter 2 numbers : ");
    scanf("%d%d", &req.x, &req.y);
    getchar();
    printf("Enter character : ");
    scanf("%c", &req.op);

    msgsnd(msgid, &req, sizeof(req), 0);

    msgrcv(msgid, &req, sizeof(req), 1, 0);
    printf("Sum : %d\n", req.r);

    return 0;
}