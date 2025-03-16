
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int num, k;
    scanf("%d %d", &num, &k);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    int different[num];
    int temp = 0;
    for (int i = 0; i < num; i++)
    {
        if (arr[i] % k != 0 || !(arr[i] / k) in different)
        {
            different.add(arr[i]);
        }
        temp = max(len(different), temp);
    }
    printf("%d", temp);
    return 0;
}

