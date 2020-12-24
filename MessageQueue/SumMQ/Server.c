#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct MQ
{
    long type;
    char op;
    int r, x, y;
} req;

int main()
{
    key_t key;
    int msgid;
    key = 1234;

    msgid = msgget(key, 0666 | IPC_CREAT);

    // Recieve from Clients
    msgrcv(msgid, &req, sizeof(req), 1, 0);

    printf("Server\nX : %d\nY : %d\nOP : %c\n", req.x, req.y, req.op);

    if (req.op == '+')
    {
        req.r = req.x + req.y;
    }
    else if (req.op == '-')
    {
        req.r = req.x - req.y;
    }
    else if (req.op == '*')
    {
        req.r = req.x * req.y;
    }
    else if (req.op == '/')
    {
        req.r = req.x / req.y;
    }
    else
    {
        req.r = 0;
    }

    req.type = 1;

    msgsnd(msgid, &req, sizeof(req), 0);
    printf("Data sent back : %d\n", req.r);

    return 0;
}