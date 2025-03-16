#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, t, current_cell, i;
    scanf("%d %d", &n, &t);
    int *s = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    current_cell = 0;
    while (current_cell <= t)
    {
        current_cell += s[current_cell - 1];
        if (current_cell == t)
        {
            printf("YES");
            exit(0);
        }
    }
    printf("NO");
    return 0;
}

