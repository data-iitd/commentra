
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[2019];
    int l = 2019;
    int m[2019];
    int a = 0;
    int r = 0;
    int i;
    int e;
    int j;

    scanf("%s", s);
    for (i = 0; i < l; i++)
    {
        m[i] = 0;
    }
    m[0] = 1;
    for (i = 0; i < strlen(s); i++)
    {
        e = s[strlen(s) - i - 1] - '0';
        a += e * pow(10, i, l);
        r += m[a % l];
        m[a % l] += 1;
    }
    printf("%d", r);
    return 0;
}

