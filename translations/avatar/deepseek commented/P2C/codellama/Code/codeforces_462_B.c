
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, k, i, j, count[26] = {0};
    char s[1000];

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    for (i = 0; i < strlen(s); i++)
    {
        count[s[i] - 'A']++;
    }

    for (i = 0; i < 26; i++)
    {
        if (count[i] >= k)
        {
            printf("%d", k * k);
            exit(0);
        }
        k -= count[i];
    }

    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            printf("%d", count[i] * count[i]);
        }
    }

    return 0;
}

