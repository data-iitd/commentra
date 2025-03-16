
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int N, M;
int A[100000];
int cum_remainders[100001];
int remainder_counts[100001];
ll combinations = 0;

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    cum_remainders[0] = 0;
    for (int i = 0; i < N; i++)
    {
        cum_remainders[i + 1] = (cum_remainders[i] + A[i]) % M;
    }
    for (int i = 0; i <= N; i++)
    {
        remainder_counts[cum_remainders[i]]++;
    }
    for (int i = 0; i <= N; i++)
    {
        combinations += (ll)remainder_counts[cum_remainders[i]] * (remainder_counts[cum_remainders[i]] - 1) / 2;
    }
    printf("%lld\n", combinations);
    return 0;
}

