
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, p = 97;
    char c[100];
    scanf("%d", &n);
    for (i = 0; i < 4; i++)
    {
        for (j = i; j < n; j += 4)
            c[j] = (char)p;
        p++;
    }
    for (i = 0; i < n; i++)
        printf("%c", c[i]);
    return 0;
}

