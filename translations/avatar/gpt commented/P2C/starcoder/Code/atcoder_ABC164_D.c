#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[2019];
    int l = 2019, m[2019], a = 0, r = 0;
    scanf("%s", s);
    for (int i = 0; i < l; i++)
        m[i] = 1;
    for (int i = l - 1; i >= 0; i--)
    {
        a += (int)s[i] * pow(10, i, l);
        r += m[a % l];
        m[a % l]++;
    }
    printf("%d", r);
    return 0;
}
