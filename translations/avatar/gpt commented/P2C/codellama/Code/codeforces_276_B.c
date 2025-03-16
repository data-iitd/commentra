#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    int i, j, cnt = 0, x = 1;
    scanf("%s", s);
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i + 1; s[j] != '\0'; j++)
        {
            if (s[i] == s[j])
            {
                cnt++;
                break;
            }
        }
    }
    if (cnt == 0)
    {
        printf("First");
    }
    else if (cnt % 2 == 0)
    {
        printf("Second");
    }
    else
    {
        printf("First");
    }
    return 0;
}
