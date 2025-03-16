#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, levels, sum, sum2, sum3, arr[levels], count, level2, level3, arr2[level3];
    scanf("%d", &n);
    scanf("%d", &levels);
    sum = 0;
    sum2 = 0;
    sum3 = 0;
    for (int i = 0; i < levels; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &level2);
    level3 = levels + level2;
    for (int i = 0; i < arr.length; i++)
    {
        arr2[i] = arr[i];
    }
    for (int i = arr.length; i < level3; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < arr2.length; i++)
    {
    }
    int arr3[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        arr3[i] = ++j;
    }
    for (int i = 0; i < n; i++)
    {
        for (int x = 0; x < arr2.length; x++)
        {
            if (arr3[i] == arr2[x])
            {
                count++;
                break;
            }
        }
    }
    if (count == n)
    {
        printf("I become the guy.\n");
    }
    else
    {
        printf("Oh, my keyboard!\n");
    }
    return 0;
}
