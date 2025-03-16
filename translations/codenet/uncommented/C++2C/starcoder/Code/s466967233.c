#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>
#include <fenv.h>
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) printf("%d\n",ans)
/*

*/
int main()
{
    ll N,K;
    ll A[200100];
    ll B[200100] = {-1};
    int now = 1;
    ll cnt = 0;
    scanf("%lld%lld",&N,&K);
    REP(i,N){
        scanf("%lld",&A[i+1]);
    }
    REP(i,200100){
        B[i] = -1;
    }
    //途中でどっかに合流したら抜ける
    ll j;
    B[1] = 0;
    for(j = 1; j <= K; j++){
        //cout << now << " -> " << A[now] << endl;
        now = A[now];
        if(B[now] == -1){
            //cout << "未到達だった" << endl;
            B[now] = j;
        }else{
            //cout << "到達済みだった" << endl;
            //cout << "B[now] = " << B[now] << endl;
            cnt = j;
            //cout << "cnt = " << cnt << endl;
            break;
        }
    }
    if(j < K){
        ll tmp;
        tmp = (K - B[now]) % (cnt -B[now]);
        //cout << "あと " << tmp << "回移動すればいい" << endl;
        //B[now]からtmp回ワープしたところが終着点
        for (ll j = 0; j < tmp; j++)
        {
            now = A[now];
        }
    }
    fin(now);
    return 0;
}

