
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int n, i, j, a, b, right, left, tmp, ans;
    scanf("%d", &n);
    int l[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int), compare);
    ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            a = l[i];
            b = l[j];
            right = bisect_left(l, a + b, i + 1, n);
            left = bisect_right(l, max(a - b, b - a), 0, i);
            tmp = max(0, right - left);
            if (left <= i < right)
            {
                tmp -= 1;
            }
            if (left <= j < right)
            {
                tmp -= 1;
            }
            ans += tmp;
        }
    }
    printf("%d", ans / 3);
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int bisect_left(int *l, int x, int low, int high)
{
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (l[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int bisect_right(int *l, int x, int low, int high)
{
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (l[mid] <= x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

