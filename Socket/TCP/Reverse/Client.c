#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int sock, server, port;
    char cdata[100], res[100];
    struct sockaddr_in saddr;

    // Create Socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    port = 5000;

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(port);

    connect(sock, (struct sockaddr *)&saddr, sizeof(saddr));

    printf("CLIENT : Entr a string ");
    scanf("%s", cdata);

    // Send
    send(sock, &cdata, sizeof(cdata), 0);

    // Recieve
    recv(sock, &res, sizeof(res), 0);
    printf("CLIENT : Result received from Server %s\n", res);

    return 0;
}