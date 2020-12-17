/**
 * C Program to demonstrate Client Server Communications using pipes
 * @author Shivaprasad Bhat
 * @date 17-12-2020
*/
#include "../Headers/headers.h"
#define READ 0
#define WRITE 1
int main()
{
    int _pipe[2];
    int _create, _read, _write, _child;
    char _message[] = "Hello from MAC";

    _create = pipe(_pipe);
    if (_create == -1)
    {
        perror("Failer to create a pipe\n");
        return 1;
    }

    _write = write(_pipe[WRITE], _message, sizeof(_message));
    printf("Message of %d bytes written to pipe\n", _write);

    _child = fork();
    if (_child == 0)
    {
        close(_pipe[WRITE]);
        char _readMessage[100];
        _read = read(_pipe[READ], _readMessage, sizeof(_readMessage));
        printf("Message read from the pipe is '%s'\n", _readMessage);
        printf("Size of the message is %d bytes\n", _read);
    }
    else if (_child > 0)
    {
        wait(NULL);
    }
    else if (_child < 0)
    {
        perror("Error while forking.\n");
        return 1;
    }

    return 0;
}