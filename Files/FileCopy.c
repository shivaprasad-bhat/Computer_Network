/**
 * C Program that copies the content of a file to another.
 * @author Shivaprasad Bhat
 * @date 17-12-2020
*/
#include "../Headers/headers.h"
int main(int argc, char *argv[])
{
    int _one, _two;
    char _ch;
    _one = open(argv[1], O_RDONLY);
    _two = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT);

    while (read(_one, &_ch, 1) == 1)
    {
        write(_two, &_ch, 1);
    }

    close(_one);
    close(_two);

    printf("Copied the contents of file 1 to file 2\n");

    return 0;
}