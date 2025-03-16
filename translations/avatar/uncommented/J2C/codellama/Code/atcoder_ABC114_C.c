
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    long i = 357;
    int c = 0;
    while (i <= N)
    {
        char s[100];
        sprintf(s, "%ld", i);
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7"))
            c++;
        char *p = s;
        int f = 0;
        while (*p)
        {
            if (f)
                *p = *(p + 1);
            else
            {
                if (*p == '3')
                {
                    *p = '5';
                    f = 1;
                }
                else if (*p == '5')
                {
                    *p = '7';
                    f = 1;
                }
                else
                {
                    *p = '3';
                    f = 1;
                }
            }
            p++;
        }
        i = atol(s);
    }
    printf("%d\n", c);
    return 0;
}

