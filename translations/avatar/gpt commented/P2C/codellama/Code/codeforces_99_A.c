#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char l[100];
    char s[100];
    char p[100];
    int i;

    // Read input from the user
    scanf("%s", l);

    // Split the input string into two parts using '.' as the delimiter
    char *token = strtok(l, ".");
    strcpy(s, token);
    token = strtok(NULL, ".");
    strcpy(p, token);

    // Extract the first character from the second part and convert it to an integer
    i = atoi(p);

    // Check if the last character of the first part is '9'
    if (s[strlen(s) - 1] == '9')
    {
        // If it is '9', print the message "GOTO Vasilisa."
        printf("GOTO Vasilisa.\n");
    }
    // Check if the last character is not '9' and the integer i is less than 5
    else if (s[strlen(s) - 1] != '9' && i < 5)
    {
        // If both conditions are true, join the list of characters into a string and print it
        printf("%s\n", s);
    }
    else
    {
        // If the last character is not '9' and i is 5 or more
        // Join the list of characters into a string, convert it to an integer, increment it by 1, and convert it back to a string
        int num = atoi(s);
        num++;
        sprintf(s, "%d", num);
        // Print the incremented value
        printf("%s\n", s);
    }

    return 0;
}

