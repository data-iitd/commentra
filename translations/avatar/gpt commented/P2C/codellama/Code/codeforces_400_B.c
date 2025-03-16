#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, m, i, j, k, l, c;
    char s[1000000];

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        scanf("%s", s);
        for (j = 0; j < strlen(s); j++)
        {
            if (s[j] == 'S')
            {
                for (k = j + 1; k < strlen(s); k++)
                {
                    if (s[k] == 'G')
                    {
                        c = j - k;
                        if (c < 0)
                        {
                            printf("-1");
                            return 0;
                        }
                        else
                        {
                            printf("%d", c);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

