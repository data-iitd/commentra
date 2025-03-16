#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char a[100], b[100], s[100];
    int i, x, c = 0;
    scanf("%s %s", a, b);
    x = (strlen(a) > strlen(b)) ? strlen(a) : strlen(b);
    for (i = 0; i < x; i++)
    {
        if (i < strlen(a))
            a[i] = a[i] - '0';
        else
            a[i] = 0;
        if (i < strlen(b))
            b[i] = b[i] - '0';
        else
            b[i] = 0;
    }
    for (i = 0; i < x; i++)
    {
        if (a[i] + b[i] + c > 9)
        {
            s[i] = (a[i] + b[i] + c) % 10 + '0';
            c = 1;
        }
        else
        {
            s[i] = (a[i] + b[i] + c) + '0';
            c = 0;
        }
    }
    if (c == 1)
        s[i] = '1';
    printf("%s\n", s);
    return 0;
}

