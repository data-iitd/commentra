#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, goal, i;
    scanf("%d %d", &n, &goal);
    int *arr = (int *)malloc(sizeof(int) * (n - 1));
    for (i = 0; i < n - 1; i++)
        scanf("%d", &arr[i]);
    int currpos = 1;
    while (currpos <= n)
    {
        if (currpos == goal)
        {
            printf("YES\n");
            break;
        }
        if (currpos == n + 1)
        {
            printf("NO\n");
            break;
        }
        currpos += arr[currpos - 1];
    }
    return 0;
}

