#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char S[100000];
    int N;
    int mod_arr[100000];
    int mod_cnt[2019];
    int radix = 1;
    scanf("%s", S);
    N = strlen(S);
    for (int i = 0; i < N; i++)
    {
        int tmp = (S[N - 1 - i] - '0') * radix % 2019;
        if (i != 0)
            tmp = (tmp + mod_arr[i - 1]) % 2019;
        mod_arr[i] = tmp;
        mod_cnt[tmp]++;
        radix = radix * 10 % 2019;
    }
    long ans = 0L;
    mod_cnt[0]++;
    for (int i = 0; i < 2019; i++)
    {
        ans += mod_cnt[i] * (mod_cnt[i] - 1) / 2;
    }
    printf("%ld\n", ans);
    return 0;
}
