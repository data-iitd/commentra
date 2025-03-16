#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a BufferedReader to read input from the standard input stream
    char str[100];
    scanf("%s", str);

    // Read a line of input, split it by spaces, and store it in an array
    char *token = strtok(str, " ");
    char *arr[100];
    int i = 0;
    while (token != NULL)
    {
        arr[i] = token;
        i++;
        token = strtok(NULL, " ");
    }

    // Create a StringTokenizer to read the next line of input
    char *st = malloc(sizeof(char) * 100);
    scanf("%s", st);

    // Parse the first token as an integer and store it in variable 'a'
    int a = atoi(strtok(st, " "));

    // Parse the second token as an integer and store it in variable 'b'
    int b = atoi(strtok(NULL, " "));

    // Read another line of input and store it in variable 'u'
    char u[100];
    scanf("%s", u);

    // Compare the string 'u' with the first element of the array 'str'
    // Print the result based on the comparison
    if (strcmp(u, arr[0]) == 0)
    {
        printf("%d %d\n", a - 1, b);
    }
    else
    {
        printf("%d %d\n", a, b - 1);
    }

    // Free the memory allocated for 'st'
    free(st);

    // End of code
    printf("