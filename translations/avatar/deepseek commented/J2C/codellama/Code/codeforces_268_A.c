
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int h[n], g[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h[i]);
        scanf("%d", &g[i]);
    }

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (h[i] == g[j])
            {
                result++;
            }
        }
    }

    printf("%d", result);

    return 0;
}

