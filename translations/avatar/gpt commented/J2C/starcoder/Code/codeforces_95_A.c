#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char **ss = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        char *s = (char*)malloc(100 * sizeof(char));
        scanf("%s", s);
        ss[i] = s;
    }
    char *cc = (char*)malloc(100 * sizeof(char));
    scanf("%s", cc);
    int m = strlen(cc);
    char c;
    scanf(" %c", &c);
    char c_ = toupper(c);
    char a = c == 'a'? 'b' : 'a';
    char a_ = toupper(a);
    bool *lucky = (bool*)malloc(m * sizeof(bool));
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
        {
            int l = strlen(ss[i]);
            if (m - j >= l && strncmp(cc + j, ss[i], l) == 0)
                for (int h = 0; h < l; h++)
                    lucky[j + h] = true;
        }
    for (int j = 0; j < m; j++)
        if (lucky[j])
        {
            if (tolower(cc[j]) == c)
                cc[j] = isupper(cc[j])? a_ : a;
            else
                cc[j] = isupper(cc[j])? c_ : c;
        }
    printf("%s\n", cc);
    return 0;
}

