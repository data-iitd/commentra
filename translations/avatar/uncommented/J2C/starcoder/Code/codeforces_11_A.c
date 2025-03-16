#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, d, i, a, result;
    scanf("%d %d", &n, &d);
    int *nums = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    result = 0;
    a = 0;
    for (i = 1; i < n; i++)
    {
        a = nums[i - 1] - nums[i];
        if (a >= 0)
        {
            result += a / d + 1;
            nums[i] += (a / d + 1) * d;
        }
    }
    printf("%d", result);
    return 0;
}
