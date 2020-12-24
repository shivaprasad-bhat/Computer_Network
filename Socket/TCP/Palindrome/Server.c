#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int port, sock, client, i, n;
    char cdata[100], rev[100];
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

    recv(client, &cdata, sizeof(cdata), 0);
    printf("SERVER : data received from Client %s\n", cdata);

    // Logic for processing
    n = strlen(cdata);
    int x = 0;
    for (i = n - 1; i >= 0; i--)
    {
        rev[x] = cdata[i];
        x++;
    }
    rev[x] = '\0';

    send(client, &rev, sizeof(rev), 0);
    printf("SERVER : result %s\n", rev);

    return 0;
}