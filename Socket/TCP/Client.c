#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int sock, server, res, clientData, port;
    struct sockaddr_in saddr;

    // Create Socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    port = 5000;

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(port);

    connect(sock, (struct sockaddr *)&saddr, sizeof(saddr));

    printf("CLIENT : Entr a number ");
    scanf("%d", &clientData);

    // Send
    send(sock, &clientData, sizeof(clientData), 0);

    // Recieve
    recv(sock, &res, sizeof(res), 0);
    printf("CLIENT : Result received from Server %d\n", res);

    return 0;
}