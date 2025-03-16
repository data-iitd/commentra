#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, t, current_cell = 0;
    scanf("%d %d", &n, &t);
    int *s = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    while (current_cell <= t)
    {
        current_cell += s[current_cell - 1];
        if (current_cell == t)
        {
            printf("YES\n");
            break;
        }
    }
    if (current_cell > t)
        printf("NO\n");
    return 0;
}
