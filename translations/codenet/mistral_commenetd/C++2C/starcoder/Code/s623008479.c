#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int l[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &l[i]);
    qsort(l, n, sizeof(int), cmpfunc);
    int ans = 0;
    for(int i = 0; i < k; i++)
        ans += l[n - 1 - i];
    printf("%d\n", ans);
    return 0;
}

