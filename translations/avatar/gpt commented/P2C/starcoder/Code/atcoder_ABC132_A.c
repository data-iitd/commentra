#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the string has exactly 2 unique characters
bool isUnique(char *S)
{
    // Create a set of unique characters from the input string
    char Sa[26] = {0};
    for (int i = 0; i < strlen(S); i++)
    {
        Sa[S[i] - 'a']++;
    }

    // Check if the number of unique characters is not equal to 2
    if (strlen(S)!= 2)
    {
        return false;
    }

    // Iterate over each unique character in the set
    for (int i = 0; i < 26; i++)
    {
        // Check if the count of the current character is not equal to 2
        if (Sa[i]!= 2)
        {
            return false;
        }
    }

    // If both conditions are satisfied, return true
    return true;
}

// Driver code
int main()
{
    // Take input string from the user
    char S[1000];
    scanf("%s", S);

    // Check if the string has exactly 2 unique characters
    if (isUnique(S))
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}

