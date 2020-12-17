/**
 * C Program to read the contents of the file that is given through command line
 * @author Shivaprasad Bhat
 * @date 17-12-2020
 * 
*/
#include "../Headers/headers.h"

int main(int argc, char *argv[])
{
    char _ch;
    FILE *_file;

    _file = fopen(argv[1], "r");
    while ((_ch = fgetc(_file)) != EOF)
    {
        printf("%c", _ch);
    }

    fclose(_file);

    return 0;
}