/**
 * C Program to accept the array in parent process and find the key in child
 * @author Sivaprasad Bhat
 * @date 17-12-2020
*/
#include "../Headers/headers.h"

int main()
{
    int _array[100], _size, _key, _child, i, _flag = 0;
    printf("Enter the size of the array : ");
    scanf("%d", &_size);

    for (i = 0; i < _size; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &_array[i]);
    }
    _child = fork();
    if (_child < 0)
    {
        perror("Error while forking\n");
        return 1;
    }
    else if (_child == 0)
    {
        printf("Enter the number to be searched : ");
        scanf("%d", &_key);
        for (i = 0; i < _size; i++)
        {
            if (_array[i] == _key)
            {
                _flag = 1;
                break;
            }
        }
        if (_flag == 1)
            printf("Element found\n");
        else
            printf("Element not found\n");
    }
    else if (_child > 0)
    {
        wait(NULL);
    }
}