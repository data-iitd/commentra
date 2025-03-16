
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    long k;
    scanf("%d %ld", &n, &k);
    long arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    qsort(arr, n, sizeof(long), cmpfunc);
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % k!= 0)
        {
            count++;
            if(arr[i] % k!= 0)
            {
                set.add(arr[i]);
            }
        }
        else if(!set.contains(arr[i] / k))
        {
            count++;
            set.add(arr[i]);
        }
    }
    printf("%d", count);
    return 0;
}

