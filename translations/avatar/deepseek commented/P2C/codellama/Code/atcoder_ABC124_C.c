
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[100];
    int i, j, count = 0;
    scanf("%s", s);
    for (i = 0; i < strlen(s); i++)
    {
        if (i % 2 == 0)
        {
            if (s[i] == '0')
                count++;
        }
        else
        {
            if (s[i] == '1')
                count++;
        }
    }
    printf("%d", count);
    return 0;
}

