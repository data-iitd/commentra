#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[4], i, j, k, s, t, ans = 10000000000000000000000000;
    char operations[3];

    for (i = 0; i < 4; i++)
        scanf("%d", &nums[i]);
    scanf("%s", operations);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (nums[j] == -1)
                continue;
            for (k = j + 1; k < 4; k++)
            {
                if (nums[k] == -1)
                    continue;
                s = nums[j];
                nums[j] = -1;
                t = nums[k];
                if (operations[i] == '+')
                    nums[k] = s + t;
                else if (operations[i] == '*')
                    nums[k] = s * t;
                if (i == 2 && nums[k] < ans)
                    ans = nums[k];
                nums[j] = s;
                nums[k] = t;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

