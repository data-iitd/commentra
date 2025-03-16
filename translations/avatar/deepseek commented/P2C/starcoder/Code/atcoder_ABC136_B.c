#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int i = 1;
    int ans = 0;
    while (pow(10, i) <= N)
    {
        ans += pow(10, i) - pow(10, i - 1);
        i += 2;
    }
    ans += max(0, N - pow(10, i - 1) + 1);
    printf("%d", ans);
    return 0;
}

