#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char s[1000];
    scanf("%s", s);
    int len = strlen(s);
    bool x = true;
    int dt[26] = {0};

    for (int i = 0; i < len; i++)
    {
        dt[s[i] - 'a']++;
    }

    int cnt = 0;
    x = true;

    for (int i = 0; i < 26; i++)
    {
        if (dt[i] % 2 != 0 && cnt < 1)
        {
            cnt++;
        }
        else if (dt[i] % 2 != 0 && cnt >= 1)
        {
            x = false;
            break;
        }
    }

    if (x)
    {
        printf("First\n");
    }
    else if (!x && len % 2 == 0)
    {
        printf("Second\n");
    }
    else if (!x && len % 2 != 0)
    {
        printf("First\n");
    }

    return 0;
}

