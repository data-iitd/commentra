#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if(arr[0] == 1)
        printf("0");
    else
    {
        long result = 1;
        for(int i = 1; i < n; i++)
            result *= arr[i] - arr[i-1];
        printf("%ld", result);
    }
    return 0;
}

