
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin,(v).end()
#define INF 1e9
#define MOD 1e9+7
typedef long long llong;
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> cnt(26, 1);
	vector<char> s(n);
	REP(i, n){
		scanf(" %c", &s[i]);
		cnt[s[i] - 'a']++;
	}

	llong ans = cnt[0];
	for(int i = 1; i < 26; ++i){
		ans *= cnt[i];
		ans %= (int)MOD;
	}

	printf("%lld\n", ans - 1);
	return 0;
}

