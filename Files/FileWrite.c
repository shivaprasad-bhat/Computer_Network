/**
 * C Program to Write the message into file
 * Introduction to Files in C
 * @author Shivaprasad Bhat
 * @date 17-12-2020
*/
#include "../Headers/headers.h"

int main()
{
    FILE *file;
    char _message[100];

    printf("Enter the message to be written to file :");
    scanf("%s", _message);

    file = fopen("SampleFile.txt", "w");
    fprintf(file, _message);
    printf("Written your message '%s' to the file\n\n", _message);
    fclose(file);
    return 0;
}