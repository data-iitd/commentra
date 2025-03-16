#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100000];
    int i, j, k, cnt = 0, x = 1;
    scanf("%s", s);
    for (i = 0; s[i]!= '\0'; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (s[i] == s[j])
            {
                cnt++;
                break;
            }
        }
        if (cnt % 2!= 0)
        {
            x = 0;
            break;
        }
        cnt = 0;
    }
    if (x)
    {
        printf("First\n");
    }
    else if (x == 0 && strlen(s) % 2 == 0)
    {
        printf("Second\n");
    }
    else if (x == 0 && strlen(s) % 2!= 0)
    {
        printf("First\n");
    }
    return 0;
}
