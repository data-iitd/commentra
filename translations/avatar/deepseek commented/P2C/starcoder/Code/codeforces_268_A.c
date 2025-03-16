
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, count = 0;
    char **q;
    scanf("%d", &n);
    q = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        char *a = (char *)malloc(100 * sizeof(char));
        scanf("%s", a);
        q[i] = a;
    }
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (j == k)
                continue;
            if (q[j][0] == q[k][strlen(q[k]) - 1])
                count++;
        }
    }
    printf("%d", count);
    return 0;
}

