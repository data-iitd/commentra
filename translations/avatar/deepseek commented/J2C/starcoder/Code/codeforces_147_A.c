
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000];
    scanf("%s", s);
    int n = strlen(s);
    char c = s[0];
    char prev = c;
    char next = s[1];
    int i;
    for(i = 1; i < n; i++)
    {
        c = s[i];
        if(isalpha(c))
        {
            if(!isalpha(prev))
            {
                printf(" ");
            }
            printf("%c", c);
        }
        else if(ispunct(c))
        {
            printf("%c", c);
        }
        prev = c;
    }
    printf("\n");
    return 0;
}

