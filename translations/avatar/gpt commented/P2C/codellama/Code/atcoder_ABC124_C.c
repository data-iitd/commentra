#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[1000];
    int i, j, count0, count1, min_changes;

    // Read input string and convert it into a list of characters
    scanf("%s", s);

    // Count the occurrences of '0' and '1' at even indices
    count0 = 0;
    count1 = 0;
    for (i = 0; i < strlen(s); i += 2)
    {
        if (s[i] == '0')
            count0++;
        else
            count1++;
    }

    // Count the occurrences of '0' and '1' at odd indices
    for (j = 1; j < strlen(s); j += 2)
    {
        if (s[j] == '0')
            count0++;
        else
            count1++;
    }

    // Calculate the minimum number of changes needed to make the string alternate
    // Option 1: Change all even indexed '0's to '1's and odd indexed '1's to '0's
    // Option 2: Change all even indexed '1's to '0's and odd indexed '0's to '1's
    // Print the minimum of the two options
    min_changes = (strlen(s) - (count0 + count1));
    printf("%d\n", min_changes);

    return 0;
}

