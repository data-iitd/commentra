
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[100], i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char str[100];
    scanf("%s", str);
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '0')
        {
            printf("%d", i + 1);
            break;
        }
    }
    return 0;
}

