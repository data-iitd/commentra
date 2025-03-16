#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000];
    scanf("%s", s);
    int n = strlen(s);
    char c = s[0];
    char *sb = (char *)malloc(sizeof(char) * (n + 1));
    sb[0] = c;
    int i;
    for (i = 1; i < n; i++)
    {
        c = s[i];
        if (c >= 'a' && c <= 'z')
        {
            if (s[i - 1] < 'a' || s[i - 1] > 'z')
            {
                sb[i] ='';
                i++;
            }
            sb[i] = c;
        }
        else if (c == '.' || c == ',' || c == '!' || c == '?')
        {
            sb[i] = c;
        }
    }
    sb[i] = '\0';
    printf("%s\n", sb);
    return 0;
}

