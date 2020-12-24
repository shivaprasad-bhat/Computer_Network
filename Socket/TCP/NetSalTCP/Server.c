#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

struct Emp
{
    float basic, da, hra, net;
} emp;

int main()
{
    int port, sock, client, i, n;

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

    recv(client, &emp, sizeof(emp), 0);

    emp.net = emp.basic - (emp.da + emp.hra);

    send(client, &emp, sizeof(emp), 0);

    printf("SERVER: Net calculated by server is %.2f\n", emp.net);

    return 0;
}