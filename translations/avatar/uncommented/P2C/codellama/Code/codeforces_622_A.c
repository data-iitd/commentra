#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, l, r, mid, idxcnt;
    scanf("%d", &n);
    l = 1;
    r = n;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        idxcnt = mid * (mid + 1) / 2;
        if (idxcnt < n)
            l = mid + 1;
        else
            r = mid;
    }
    l -= 1;
    idxcnt = l * (l + 1) / 2;
    printf("%d", n - idxcnt);
    return 0;
}
