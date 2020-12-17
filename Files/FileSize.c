/**
 * C Program to find the size of the file in bytes
 * Introduction to Files using C
 * @author Shivaprasad Bhat
 * @date 17-12-2020
*/
#include "../Headers/headers.h"

int main(int argc, char *argv[])
{

    char _fileName[100];
    int _bytes;
    FILE *_file;

    strcpy(_fileName, argv[1]);

    _file = fopen(_fileName, "r");
    fseek(_file, SEEK_SET, SEEK_END);
    _bytes = ftell(_file);
    fclose(_file);

    printf("Total size of the file is %d\n", _bytes);

    return 0;
}