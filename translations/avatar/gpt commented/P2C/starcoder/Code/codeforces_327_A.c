#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    char s[100000];
    int i, j, k, l, m, maximum;
    scanf("%d", &n);
    scanf("%s", s);
    for (i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            break;
        }
    }
    if (i == n)
    {
        printf("%d\n", n);
    }
    else
    {
        maximum = 0;
        for (j = 0; j < n - 1; j++)
        {
            if (s[j] == '0' && s[j + 1] == '0')
            {
                for (k = j + 1; k < n - 1; k++)
                {
                    if (s[k] == '0')
                    {
                        break;
                    }
                }
                for (l = j + 1; l < k; l++)
                {
                    if (s[l] == '0')
                    {
                        break;
                    }
                }
                for (m = k + 1; m < n - 1; m++)
                {
                    if (s[m] == '0')
                    {
                        break;
                    }
                }
                maximum = max(maximum, 2 + 2 * (abs(j - k) - 1) - (abs(l - m) - 1));
            }
        }
        printf("%d\n", n - 1 + maximum);
    }
    return 0;
}

