/**
 * C Program to find the size of the file in bytes
 * Introduction to Files using C
 * @author Shivaprasad Bhat
 * @date 17-12-2020
*/
#include "../Headers/headers.h"

int main(int argc, char *argv[])
{
    int _bytes;
    FILE *_file;

    _file = fopen(argv[1], "r");
    fseek(_file, SEEK_SET, SEEK_END); /*SEEK_SET : Start, SEEk_CUR : Current, SEK_END : End*/
    _bytes = ftell(_file);
    fclose(_file);

    printf("Total size of the file is %d\n", _bytes);

    return 0;
}