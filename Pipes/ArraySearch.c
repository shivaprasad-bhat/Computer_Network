/**
 * C Program to accept the array in server, find an element in client and display result in server
 * 2 way communication using 2 pipes
 * @author Shivaprasad Bhat
 * @date 17-12-2020
 */

#include "../Headers/headers.h"
#define READ 0
#define WRITE 1

int main()
{
    int _pipe1[2], _pipe2[2], _read, _write;
    int _createPipe1, _createPipe2;
    int _array[100], _size, _key, i, _flag = 0, _child;

    // Parent process : Accept the Array
    printf("Enter the size of the array : ");
    scanf("%d", &_size);
    for (i = 0; i < _size; i++)
    {
        printf("Enter the element %d : ", i + 1);
        scanf("%d", &_array[i]);
    }

    _createPipe1 = pipe(_pipe1);
    _createPipe2 = pipe(_pipe2);

    if (_createPipe1 == -1 || _createPipe2 == -1)
    {
        perror("Failed to create pipes\n");
        return 0;
    }

    _write = write(_pipe1[WRITE], _array, sizeof(_array));
    printf("Written %d bytes to the pipe from parent\n\n", _write);

    _child = fork();
    if (_child == 0)
    {
        int _readArray[100];
        printf("Enter the key to be searched : ");
        scanf("%d", &_key);

        close(_pipe1[WRITE]);
        _read = read(_pipe1[READ], _readArray, sizeof(_readArray));
        for (i = 0; i < _size; i++)
        {
            if (_readArray[i] == _key)
            {
                _flag = 1;
                break;
            }
        }

        _write = write(_pipe2[WRITE], &_flag, sizeof(_flag));
        printf("Written %d bytes to pipe 2 from child\n\n", _write);
        printf("Result to the pipe 2 is %d\n\n", _flag);
    }
    else if (_child > 1)
    {
        wait(NULL);
        int _result;
        close(_pipe2[WRITE]);
        _read = read(_pipe2[READ], &_result, sizeof(_result));

        printf("Read %d bytes from pipe 2 in parent\n", _read);
        printf("Result from pipe is is %d\n\n", _result);
        if (_result == 1)
        {
            printf("Element found\n");
        }
        else
        {
            printf("Element not found\n");
        }
    }
    else if (_child < 0)
    {
        perror("Failed to create fork\n");
        return 1;
    }

    return 0;
}