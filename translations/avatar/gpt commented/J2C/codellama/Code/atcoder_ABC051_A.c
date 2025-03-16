#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Creating a BufferedReader to read input from the console
    char a[100];
    printf("Enter a string: ");
    scanf("%s", a);

    // Replacing commas in the input string with spaces and appending to StringBuilder
    char *str = strtok(a, ",");
    while (str != NULL)
    {
        printf("%s ", str);
        str = strtok(NULL, ",");
    }

    // Printing the modified string to the console
    printf("\n");

    return 0;
}
