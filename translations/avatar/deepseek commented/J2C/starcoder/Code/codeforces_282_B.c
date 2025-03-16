#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, flag, dif, s1, s2, x, y;
    char ch[100000];
    scanf("%d", &n);
    s1 = s2 = 0;
    j = 0;
    flag = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        dif = s1 - s2;
        if(dif < -500)
        {
            s1 += x;
            ch[j++] = 'A';
        }
        else if(dif > 500)
        {
            s2 += y;
            ch[j++] = 'G';
        }
        else
        {
            if(s1 + x <= 500)
            {
                s1 += x;
                ch[j++] = 'A';
            }
            else if(s2 + y <= 500)
            {
                s2 += y;
                ch[j++] = 'G';
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 1)
        printf("-1\n");
    else
    {
        ch[j] = '\0';
        printf("%s\n", ch);
    }
    return 0;
}

