#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char result[100];

    // Read input from the standard input (user input)
    scanf("%s", s);

    // Check if both 'A' and 'B' are present in the input string
    // If both are found, set result to "Yes", otherwise set it to "No"
    if (strstr(s, "A") && strstr(s, "B"))
    {
        strcpy(result, "Yes");
    }
    else
    {
        strcpy(result, "No");
    }

    // Print the result indicating whether both 'A' and 'B' were found
    printf("%s\n", result);

    return 0;
}

