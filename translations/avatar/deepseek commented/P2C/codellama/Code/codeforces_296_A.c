
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    char *str;
    int count = 0;
    int i, j;
    int flag = 0;

    // Take an integer input representing the threshold
    scanf("%d", &n);

    // Take a space-separated string input and split it into a list
    str = (char *)malloc(100 * sizeof(char));
    scanf("%s", str);

    // Iterate over the unique elements in the list `m`
    for (i = 0; i < strlen(str); i++)
    {
        // Check if the count of the current element is greater than or equal to n / 2 + 1
        for (j = i + 1; j < strlen(str); j++)
        {
            if (str[i] == str[j])
            {
                count++;
            }
        }

        if (count >= n / 2 + 1)
        {
            flag = 1;
            break;
        }
        count = 0;
    }

    // Print 'YES' if possible is True, otherwise print 'NO'
    if (flag == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}

