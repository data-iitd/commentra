#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sqr(x) ((x) * (x))
#define INF 1000000000
#define MOD 1000000007
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

int main()
{
    int N, X, A[100000];
    scanf("%d%d", &N, &X);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    int S[100000];
    S[0] = A[0];
    for (int i = 1; i < N; i++)
        S[i] = S[i - 1] + A[i];
    int ans = INT_MAX;
    for (int k = 1; k <= N / 2; k++)
    {
        int E = k * X + 2 * (S[N - 2 * k - 1] - S[N - 2 * k - 1 - k]);
        ans = min(ans, E);
    }
    printf("%d\n", ans + N * X + 5 * S[N - 1]);
    return 0;
}

