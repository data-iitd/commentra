#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    LL n,c;
    scanf("%lld %lld",&n,&c);

    LL *x = (LL *)malloc((n+1)*sizeof(LL));
    LL *v = (LL *)malloc((n+1)*sizeof(LL));

    for(int i = 1; i < n+1; i++){
        scanf("%lld %lld",&x[i],&v[i]);
    }

    LL *lefttotal = (LL *)malloc((n+1)*sizeof(LL));
    LL *maxlefttotal = (LL *)malloc((n+1)*sizeof(LL));
    for(int i = 1; i < n+1; i++){
        lefttotal[i] = lefttotal[i-1] + v[i];
    }

    for(int i = 1; i < n+1; i++){
        maxlefttotal[i] = max(maxlefttotal[i-1],lefttotal[i]-x[i]);
    }

    LL *righttotal = (LL *)malloc((n+1)*sizeof(LL));
    LL *maxrighttotal = (LL *)malloc((n+1)*sizeof(LL));
    for(int i = 1; i < n+1; i++){
        righttotal[i] = righttotal[i-1] + v[n-i+1];
    }
    
    for(int i = 1; i < n+1; i++){
        maxrighttotal[i] = max(maxrighttotal[i-1],righttotal[i] -(c - x[n+1-i]));
    }

    LL ans = 0;

    for(int i = 1; i < n+1; i++){
        ans = max(ans,lefttotal[i]-x[i]);
        ans = max(ans,lefttotal[i]-2*x[i]+maxrighttotal[n-i]);
        ans = max(ans,righttotal[i]-(c -x[n+1-i]));
        ans = max(ans,righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i]);
    }

    printf("%lld\n",ans);
    
    return 0;
}
