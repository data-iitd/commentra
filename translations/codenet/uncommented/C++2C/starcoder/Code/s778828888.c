#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    int n, m, x;
    int a[105] = {};
    scanf("%d %d %d", &n, &m, &x);

    for(int i = 0; i < m; ++i)
    {
        int temp;
        scanf("%d", &temp);
        a[temp] = 1;
    }

    int ansl = 0, ansr = 0, i;
    for(i = x; i <= n; ++i)
    {
        ansr += a[i];
    }
    for(i=x; i >= 0; --i)
    {
        ansl += a[i];
    }

    printf("%d\n", std::min(ansl, ansr));
    return 0;
}
