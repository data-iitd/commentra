#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char **l = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        l[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", l[i]);
    }
    char f = 'Y';
    int i = -1;
    char *s[100];
    for (int i = 0; i < 100; i++)
    {
        s[i] = (char *)malloc(100 * sizeof(char));
        strcpy(s[i], "");
    }
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (s[j][0]!= '\0')
        {
            j++;
        }
        if (strcmp(s[j], l[i]) == 0)
        {
            s[j][0] = l[i][0];
            s[j][1] = '\0';
        }
        else
        {
            int k = 0;
            while (s[k][0]!= '\0')
            {
                k++;
            }
            if (k == j)
            {
                strcpy(s[k], l[i]);
            }
            else
            {
                f = 'N';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (s[j][0]!= '\0')
        {
            j++;
        }
        if (j >= 2)
        {
            f = 'N';
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (s[j][0]!= '\0')
        {
            j++;
        }
        if (i!= 0 && l[i - 1][strlen(l[i - 1]) - 1]!= l[i][0])
        {
            f = 'N';
        }
    }
    printf("%c", f);
    return 0;
}

