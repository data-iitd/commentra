#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000000];
    int l = 2019, m[2020] = {0}, a = 0, r = 0;
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        a += (int)s[i] * pow(10, i, l);
        m[a % l]++;
        r += m[a % l];
    }
    printf("%d", r);
    return 0;
}

