#include <stdio.h>
#include <string.h>

int main()
{
    // Declare a character array to hold the input string with a maximum length of 100 characters
    char mes[101];

    // Read a string from standard input and store it in the 'mes' array
    scanf("%s", mes);

    // Print the first character of the string, the length of the string minus 2, and the last character of the string
    printf("%c%lu%c\n", mes[0], strlen(mes) - 2, mes[strlen(mes) - 1]);

    // Return 0 to indicate successful completion of the program
    return 0;
}
