#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MOD 1000000007

int main()
{
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    int ans = 0;
    int rep = N / (A + B);
    ans += rep * A;
    int res = N - rep * (A + B);
    ans += min(res, A);
    printf("%d\n", ans);
    return 0;
}
