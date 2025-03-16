#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, k, temp = 0;
    scanf("%d %d", &num, &k);
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < num; i++)
    {
        if (arr[i] % k!= 0 ||!arr[i] / k in different)
        {
            different.add(arr[i]);
        }
        temp = max(len(different), temp);
    }
    printf("%d", temp);
    return 0;
}

