#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int l = 2019;
    int m[l];
    int a = 0;
    int r = 0;
    int i;
    char s[100000];
    scanf("%s", s);
    for(i=0;i<l;i++)
        m[i] = 0;
    for(i=0;i<strlen(s);i++)
    {
        a += (int)s[i] * pow(10, i, l);
        r += m[a%l];
        m[a%l] += 1;
    }
    printf("%d\n", r);
    return 0;
}

