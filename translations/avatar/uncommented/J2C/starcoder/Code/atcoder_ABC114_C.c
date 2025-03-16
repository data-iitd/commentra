#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    long i = 357;
    int c = 0;
    while (i <= N)
    {
        char s[100];
        sprintf(s, "%ld", i);
        if (strstr(s, "3") && strstr(s, "5") && strstr(s, "7"))
            c++;
        char sb[100];
        int f = 0;
        for (int j = 0; j < strlen(s); j++)
        {
            char a = s[strlen(s) - 1 - j];
            if (f)
            {
                strcat(sb, a);
            }
            else
            {
                if (a == '3')
                {
                    strcat(sb, "5");
                    f = 1;
                }
                else if (a == '5')
                {
                    strcat(sb, "7");
                    f = 1;
                }
                else
                {
                    strcat(sb, "3");
                }
            }
        }
        if (!f)
            strcat(sb, "3");
        char sb2[100];
        strcpy(sb2, sb);
        strrev(sb2);
        i = atol(sb2);
    }
    printf("%d\n", c);
    return 0;
}

