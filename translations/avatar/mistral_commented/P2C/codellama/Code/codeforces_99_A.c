#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *l, *s, *p, last_char;
    int i, j, len, len1, len2;

    // Get the input string from the user
    printf("Enter the string: ");
    scanf("%s", l);

    // Split the input string using '.' as delimiter and store the list in 'l'
    s = strtok(l, ".");
    p = strtok(NULL, ".");

    // Extract the first and second parts of the list and store them in 's' and 'p' respectively
    len = strlen(s);
    len1 = strlen(p);

    // Get the last character of the string 's' and store it in a variable 'last_char'
    last_char = s[len - 1];

    // Check if the last character of the string 's' is '9'
    if (last_char == '9')
    {
        // If yes, print the message "GOTO Vasilisa."
        printf("GOTO Vasilisa.\n");
    }

    // Else, if the last character is not '9' and the integer value of the first part of 'p' is less than 5
    else if (last_char != '9' && atoi(p) < 5)
    {
        // Concatenate all the characters of 's' to form a string
        for (i = 0; i < len; i++)
        {
            s[i] = s[i];
        }
        s[len] = '\0';

        // Print the string 's'
        printf("%s\n", s);
    }

    // Else, if the last character is not '9' and the integer value of the first part of 'p' is greater than or equal to 5
    else
    {
        // Concatenate all the characters of 's' to form a string
        for (i = 0; i < len; i++)
        {
            s[i] = s[i];
        }
        s[len] = '\0';

        // Increment the last character of the string 's' by 1
        s[len - 1] = s[len - 1] + 1;

        // Print the updated string 's'
        printf("%s\n", s);
    }

    return 0;
}

