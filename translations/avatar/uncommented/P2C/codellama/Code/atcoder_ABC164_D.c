
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[2019];
    int l = 2019;
    int m[2019] = {1}, a = 0, r = 0;
    int i, e;
    scanf("%s", s);
    for (i = 0; i < strlen(s); i++)
    {
        a += (s[i] - '0') * pow(10, i, l);
        r += m[a % l];
        m[a % l] += 1;
    }
    printf("%d", r);
    return 0;
}

