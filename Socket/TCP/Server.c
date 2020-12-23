#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int port, sock, client;
    int clientData, res;
    struct sockaddr_in sadd, cadd;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    port = 5000;

    sadd.sin_family = AF_INET;
    sadd.sin_addr.s_addr = INADDR_ANY;
    sadd.sin_port = htons(port);

    // Bind
    bind(sock, (struct sockaddr *)&sadd, sizeof(sadd));

    //Listen
    listen(sock, 5);

    int cl = sizeof(cadd);
    client = accept(sock, (struct sockaddr *)&cadd, &cl); // Block mode

    recv(client, &clientData, sizeof(clientData), 0);
    printf("SERVER : data received from Client %d\n", clientData);

    // Logic for processing
    res = clientData + 100;
    send(client, &res, sizeof(res), 0);
    printf("SERVER : result %d\n", res);

    return 0;
}