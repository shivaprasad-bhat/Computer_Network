#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
struct MQ
{
    long type;
    char str[100];
} mq;

int main()
{

    char revstr[100];
    key_t key;
    int msgid, flag = 1, i, n, x;

    key = 1234;

    msgid = msgget(key, 0666 | IPC_CREAT);

    msgrcv(msgid, &mq, sizeof(mq), 1, 0);

    n = strlen(mq.str);
    int s = 0;
    for (i = n - 1; i >= 0; i--)
    {
        revstr[s] = mq.str[i];
        s++;
    }
    revstr[s] = '\0';
    flag = strcmp(mq.str, revstr);
    printf("Actual String : %s\n", mq.str);
    printf("Reversed String: %s \n", revstr);
    printf("Flag = %d\n", flag);

    if (flag == 0)
    {
        printf("Palindrom\n");
    }
    else
    {
        printf("Not palindrome\n");
    }

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}