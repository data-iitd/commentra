#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100000];
    scanf("%s", s);
    int x = 1, cnt = 0;
    int len = strlen(s);
    int i;
    for (i = 0; i < len; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            cnt++;
        }
    }
    if (cnt > 1)
    {
        x = 0;
    }
    if (x == 1)
    {
        if (len % 2 == 0)
        {
            printf("First\n");
        }
        else
        {
            printf("Second\n");
        }
    }
    else
    {
        if (len % 2 == 0)
        {
            printf("Second\n");
        }
        else
        {
            printf("First\n");
        }
    }
    return 0;
}
