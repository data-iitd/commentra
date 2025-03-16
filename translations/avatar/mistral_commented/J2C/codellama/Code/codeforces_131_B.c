
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, cnt[21] = {0};

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        cnt[num + 10]++;
    }

    long res = 0;
    for (i = 0; i < 10; i++)
    {
        res += cnt[i] * cnt[20 - i];
    }
    res += (cnt[10] * (cnt[10] - 1)) / 2;

    printf("%ld\n", res);

    return 0;
}

