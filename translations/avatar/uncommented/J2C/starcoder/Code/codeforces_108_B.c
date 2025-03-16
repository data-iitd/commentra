#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), compare);
    for(int i = 0; i < n - 1; i++)
        if(a[i + 1] < a[i] * 2 && a[i]!= a[i + 1])
        {
            printf("YES\n");
            return 0;
        }
    printf("NO\n");
    return 0;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

