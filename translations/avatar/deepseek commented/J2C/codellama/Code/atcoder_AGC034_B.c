
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[1000000];
    int i, j, cnt = 0, tmp = 0;
    scanf("%s", s);
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'A')
        {
            tmp++;
        }
        else if (s[i] == 'D')
        {
            cnt += tmp;
        }
        else
        {
            tmp = 0;
        }
    }
    printf("%d", cnt);
    return 0;
}
// The C code reads the input string, replaces all occurrences of "BC" with "D", and then counts the number of consecutive 'A's.

