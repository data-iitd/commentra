#include <stdio.h>

int main()
{
    int n, i, arr[100], flag = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    if (arr[0] > 15)
    {
        printf("15\n");
    }
    else
    {
        for (i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] > 15)
            {
                printf("%d\n", arr[i - 1] + 15);
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            if (arr[n - 1] == 90 || arr[n - 1] + 15 >= 90)
            {
                printf("90\n");
            }
            else
            {
                printf("%d\n", arr[n - 1] + 15);
            }
        }
    }

    return 0;
}

