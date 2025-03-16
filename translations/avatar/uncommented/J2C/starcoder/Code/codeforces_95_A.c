#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n, i, j, m;
    char **ss, *cc;
    scanf("%d", &n);
    ss = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++)
    {
        ss[i] = (char*)malloc(100 * sizeof(char));
        scanf("%s", ss[i]);
    }
    scanf("%s", cc);
    m = strlen(cc);
    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            int l = strlen(ss[i]);
            if(m - j >= l &&!strcmp(cc + j, ss[i]))
            {
                for(int h = 0; h < l; h++)
                    cc[j + h] = toupper(cc[j + h]);
            }
        }
    }
    printf("%s\n", cc);
    return 0;
}

