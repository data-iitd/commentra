#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP3(i, m, n) for (int i = (m); i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(v) sort(ALL(v))
#define MAX(v) *max_element(ALL(v))
#define MIN(v) *min_element(ALL(v))
#define SZ(v) ((int)(v).size())
#define CONTAINS(v, x) ((v).find(x)!= (v).end())
#define SQR(x) ((x) * (x))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) (int)(ceil(log2((double)(n))))
#define BIT(n, i) (((n) >> (i)) & 1)
#define BITS(n) ((int)(ceil(log2((double)(n)))))
#define PRIME_TABLE_SIZE 10000010
#define INF (int)(1e9)
#define MOD 1000000007

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<P> VP;
typedef vector<VP> VVP;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef vector<bool> VB;

int n, x;
int A[1000010];

int main() {
	n = ReadInt();
	x = ReadInt();
	REP(i, n) {
		A[i] = ReadInt();
	}
	SORT(A);
	int ans = 0;
	REP(i, n) {
		if (x >= A[i]) {
			ans++;
			x -= A[i];
		} else {
			break;
		}
	}
	if (ans == n && x > 0) {
		ans--;
	}
	printf("%d\n", ans);
	return 0;
}

