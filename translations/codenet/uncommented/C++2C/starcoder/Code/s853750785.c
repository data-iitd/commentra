
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define rep2(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define endl '\n'
#define sqr(x) ((x)*(x))
#define INF 1000000000
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vpii> vvpii;
typedef pair<int,pii> pipii;
typedef vector<pipii> vpipii;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int H[100005];
	rep(i, N)scanf("%d", &H[i]);
	rep(i, M) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll ans = 0;
	rep(u, N) {
		bool flag = true;
		for (int v : G[u]) {
			if (H[u] <= H[v])flag = false;
		}
		if (flag)ans++;
	}
	printf("%lld", ans);
	return 0;
}

