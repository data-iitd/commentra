#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    long arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%ld", &arr[i]);
    }
    long answer = abs(arr[0]);
    for(int i = 1; i < n; i++)
    {
        answer += abs(arr[i] - arr[i-1]);
    }
    printf("%ld", answer);
    return 0;
}
