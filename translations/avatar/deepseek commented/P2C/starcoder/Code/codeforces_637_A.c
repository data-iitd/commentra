#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, c, a;
    char s[100000];
    scanf("%d", &n);
    scanf("%s", s);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i] > s[j])
            {
                k = s[i];
                s[i] = s[j];
                s[j] = k;
            }
        }
    }
    c = -1;
    a = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
            {
                if (i > c)
                {
                    c = i;
                    a = s[i];
                }
            }
        }
    }
    printf("%c", a);
    return 0;
}

