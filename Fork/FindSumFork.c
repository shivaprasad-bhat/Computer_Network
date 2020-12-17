/**
 * C Program that accepts two numbers in parent process and finds the sum in child process
 * @author Shivaprasad Bhat
 * @date 17-12-2020
*/
#include "../Headers/headers.h"

int main()
{
    int _one, _two, _child;

    printf("Enter two numbers : ");
    scanf("%d%d", &_one, &_two);

    _child = fork();
    if (_child < 0)
    {
        perror("Error while forking\n");
        return 1;
    }
    else if (_child == 0)
    {
        int _sum;
        _sum = _one + _two;
        printf("Sum of %d and %d is %d\n", _one, _two, _sum);
    }
    else if (_child > 0)
    {
        wait(NULL);
    }

    return 0;
}