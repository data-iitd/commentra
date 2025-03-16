#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, ans;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    ans = arr[0] + 1;
    for(i=1; i<n; i++)
        ans += abs(arr[i] - arr[i-1]) + 2;
    printf("%d", ans);
    return 0;
}
