#include <stdio.h>
#include <string.h>

/* The main function is the entry point of the program */
int main(int argc, char *argv[])
{
    /* Declare a character array 'buf' of size 512 */
    char buf[512];

    /* Declare an integer variable 'len' to store the length of the string read */
    int len;

    /* Read a line from standard input using fgets() and store it in 'buf' */
    fgets(buf, sizeof(buf), stdin);

    /* Calculate the length of the string read and store it in 'len' */
    len = strlen(buf);

    /* Print the first character of the string, its length (minus 3), and the last character of the string */
    print(buf[0], len-3, buf[len-2])

    /* Return 0 to indicate successful execution of the program */
    return 0;
}

