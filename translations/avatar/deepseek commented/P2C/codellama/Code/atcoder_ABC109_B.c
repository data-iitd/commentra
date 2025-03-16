#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, count;
    char *str[1000];
    char *temp;
    char *first;
    char *last;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        str[i] = (char *)malloc(1000 * sizeof(char));
        scanf("%s", str[i]);
    }

    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (strcmp(str[i], str[j]) == 0)
            {
                count++;
            }
        }
        if (count >= 2)
        {
            printf("No");
            return 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        first = str[i];
        last = str[i + 1];
        if (first[strlen(first) - 1] != last[0])
        {
            printf("No");
            return 0;
        }
    }

    printf("Yes");

    return 0;
}

