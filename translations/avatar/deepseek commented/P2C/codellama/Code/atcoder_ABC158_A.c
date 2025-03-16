
#include <stdio.h>
#include <string.h>

int main()
{
    char stdin[100];
    char s[100];
    char result[100];

    // Take input from the user and store it in the variable stdin
    scanf("%s", stdin);

    // Assign the input to the variable s
    strcpy(s, stdin);

    // Check if the string s contains both "A" and "B"
    if (strstr(s, "A") && strstr(s, "B"))
    {
        // If both "A" and "B" are in the string, set result to "Yes"
        strcpy(result, "Yes");
    }
    else
    {
        // Otherwise, set result to "No"
        strcpy(result, "No");
    }

    // Print the result
    printf("%s\n", result);

    return 0;
}

