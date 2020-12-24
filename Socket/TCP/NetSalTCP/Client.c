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
    int sock, server, port;
    struct sockaddr_in saddr;

    // Create Socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    port = 5000;

    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(port);

    connect(sock, (struct sockaddr *)&saddr, sizeof(saddr));

    printf("Enert Basic, DA, HRA : ");
    scanf("%f%f%f", &emp.basic, &emp.da, &emp.hra);

    send(sock, &emp, sizeof(emp), 0);

    // Recieve
    recv(sock, &emp, sizeof(emp), 0);

    printf("CLIENT: Net sent by server is %.2f\n", emp.net);

    return 0;
}