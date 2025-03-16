
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MOD 1000000007
#define MAX 2147483647
#define LMAX 9223372036854775807

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N];
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    int idx[N], pos[N];
    int next = 0, cur = 0;
    bool used[N];
    memset(used, 0, sizeof(used));
    while(!used[next])
    {
        used[next] = true;
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }
    long a = cur - idx[next];
    long b = idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);
    if(b > K)
        ans = (int)K;
    printf("%d\n", pos[ans] + 1);
    return 0;
}

