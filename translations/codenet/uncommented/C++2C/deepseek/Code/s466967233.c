#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip.h> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) printf("%s\n", (ans))
/*

*/
int main()
{
    ll N,K;
    ll A[200100];
    ll B[200100] = {-1};
    int now = 1;
    ll cnt = 0;
    scanf("%lld %lld", &N, &K);
    REP(i,N){
        scanf("%lld", &A[i+1]);
    }
    REP(i,200100){
        B[i] = -1;
    }
    //途中でどっかに合流したら抜ける
    ll j;
    B[1] = 0;
    for(j = 1; j <= K; j++){
        //printf("%d -> %d\n", now, A[now]);
        now = A[now];
        if(B[now] == -1){
            //printf("未到達だった\n");
            B[now] = j;
        }else{
            //printf("到達済みだった\n");
            //printf("B[now] = %d\n", B[now]);
            cnt = j;
            //printf("cnt = %d\n", cnt);
            break;
        }
    }
    if(j < K){
        ll tmp;
        tmp = (K - B[now]) % (cnt -B[now]);
        //printf("あと %d回移動すればいい\n", tmp);
        //B[now]からtmp回ワープしたところが終着点
        for (ll j = 0; j < tmp; j++)
        {
            now = A[now];
        }
    }
    printf("%d\n", now);
    return 0;
}
