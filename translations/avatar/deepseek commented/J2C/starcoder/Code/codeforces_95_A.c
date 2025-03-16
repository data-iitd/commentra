#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, m, l, h;
    char c, c_, a, a_;
    char **ss, *cc;
    int *lucky;
    scanf("%d", &n);
    ss = (char**)malloc(n*sizeof(char*));
    for(i=0; i<n; i++)
    {
        scanf("%s", ss[i]);
    }
    scanf("%s", cc);
    scanf("%c", &c);
    c_ = c - 'a' + 'A';
    a = c == 'a'? 'b' : 'a';
    a_ = a - 'a' + 'A';
    m = strlen(cc);
    lucky = (int*)malloc(m*sizeof(int));
    for(j=0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {
            l = strlen(ss[i]);
            if(m-j>=l &&!strcmp(cc+j, ss[i]))
            {
                for(h=0; h<l; h++)
                {
                    lucky[j+h] = 1;
                }
            }
        }
    }
    for(j=0; j<m; j++)
    {
        if(lucky[j])
        {
            if(cc[j] == c)
            {
                cc[j] = a;
            }
            else
            {
                cc[j] = c;
            }
        }
    }
    printf("%s\n", cc);
    return 0;
}

