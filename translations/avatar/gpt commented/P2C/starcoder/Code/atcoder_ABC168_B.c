#include <stdio.h>
#include <string.h>

int main()
{
    // Read an integer input K from the user
    int K;
    scanf("%d", &K);
    
    // Read a string input S from the user
    char S[1000];
    scanf("%s", S);
    
    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K)
    {
        // If true, return the original string S
        printf("%s", S);
    }
    else
    {
        // If the length of S is greater than K, return the first K characters followed by '...'
        printf("%.*s...", K, S);
    }
    
    return 0;
}

