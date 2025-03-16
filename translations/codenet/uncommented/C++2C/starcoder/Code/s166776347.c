#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define N 1000000
#define mod 1000000007

int main() {
	// 入力
	int N,K;scanf("%d%d",&N,&K);
	int A[N];REP(i,N)scanf("%d",&A[i]);

	// 解法 
    int ans1 = 0;
	REP(i,N){
        REP(j,N){
            if (i>=j) continue;
            if (A[i]>A[j]) ans1++;
            ans1 %= mod;
        }
    }
    

    int count[2005] = {0};
    REP(i,N){
        count[A[i]-1]++;
    }
	// REP(i,3) printf("%lld, ", count[i]);
	// printf("\n");
    int ans2 = 0;
    int remain = N;
    REP(i,2005){
        remain -= count[i];
        ans2 += count[i]*remain;
    }
	// cout << ans1 << endl;
	// cout << ans2 << endl;
    // K %= mod;
    int ans = 0;
    int tmp = K*(K-1);
    tmp /= 2;
    tmp %= mod;
    tmp *= ans2;
    tmp %= mod;
    ans += ans1 * K;
    ans %= mod;
    ans += tmp;
    ans %= mod;
	//出力
	printf("%d\n", ans);
}

