#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin,(v).end()
#define INF 1e9
#define MOD 1e9+7
typedef long long llong;
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int cnt[26] = {0};
	char s[n];
	REP(i, n){
		scanf("%c", &s[i]);
		cnt[s[i] - 'a']++;
	}

	llong ans = cnt[0];
	for(int i = 1; i < 26; ++i){
		ans *= cnt[i];
		ans %= MOD;
	}

	printf("%lld\n", ans - 1);
	return 0;
}

