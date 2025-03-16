#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>

int main()
{
    int r, g, b, n;
    scanf("%d %d %d %d", &r, &g, &b, &n);
    int ans = 0;
    for (int i = 0; i <= n / r; ++i)
    {
        for (int j = 0; j <= n / g; ++j)
        {
            int num = n - r * i - g * j;
            if (num >= 0 && num % b == 0)
            {
                ++ans;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}

