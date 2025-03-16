
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, m, l;
    char **ss, *cc, c, a, c_, a_;
    int *lucky;
    scanf("%d", &n);
    ss = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++)
    {
        ss[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", ss[i]);
    }
    cc = (char*)malloc(100 * sizeof(char));
    scanf("%s", cc);
    m = strlen(cc);
    c = getchar();
    c_ = toupper(c);
    a = c == 'a'? 'b' : 'a';
    a_ = toupper(a);
    lucky = (int*)malloc(m * sizeof(int));
    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            l = strlen(ss[i]);
            if(m - j >= l &&!strcmp(cc + j, ss[i]))
            {
                for(int h = 0; h < l; h++)
                {
                    lucky[j + h] = 1;
                }
            }
        }
    }
    for(j = 0; j < m; j++)
    {
        if(lucky[j])
        {
            if(tolower(cc[j]) == c)
            {
                cc[j] = isupper(cc[j])? a_ : a;
            }
            else
            {
                cc[j] = isupper(cc[j])? c_ : c;
            }
        }
    }
    printf("%s\n", cc);
    return 0;
}

