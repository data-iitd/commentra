#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Initialize an empty list 's' by taking input from the user
    char s[1000];
    scanf("%s", s);

    // Create two dictionaries 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the list 's' respectively
    int even[2] = {0};
    int odd[2] = {0};

    // Count the frequency of '0' and '1' in the first half of the list 's'
    for (int i = 0; i < strlen(s) / 2; i++)
    {
        if (s[i] == '0')
        {
            even[0]++;
        }
        else if (s[i] == '1')
        {
            even[1]++;
        }
    }

    // Count the frequency of '0' and '1' in the second half of the list 's'
    for (int i = strlen(s) / 2; i < strlen(s); i++)
    {
        if (s[i] == '0')
        {
            odd[0]++;
        }
        else if (s[i] == '1')
        {
            odd[1]++;
        }
    }

    // Print the minimum difference between the length of the list 's' and the sum of the frequencies of '0' and '1' in either half of the list
    printf("%d", abs(strlen(s) - (even[0] + odd[1])));

    return 0;
}

