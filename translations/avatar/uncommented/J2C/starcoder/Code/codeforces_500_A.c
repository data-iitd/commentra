#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, goal, i, j, k, flag;
    scanf("%d %d", &n, &goal);
    int *arr = (int *)malloc(sizeof(int) * (n - 1));
    for (i = 0; i < n - 1; i++)
        scanf("%d", &arr[i]);
    flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] == goal)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
