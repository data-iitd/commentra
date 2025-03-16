
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <bitset>

#define MOD 1000000007

typedef long long LL;
typedef unsigned long long ULL;

ULL mod_pow(ULL x, ULL n){
    ULL ans = 1;
    while(n>0){
        if((n&1)==1){
            ans = ans * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return ans;
}

ULL comb_s(ULL n, ULL r){
    ULL tmp_n=1;
    ULL tmp_d=1;
    ULL ans;
    for(int i=1; i<=r; i++){
        tmp_n=(tmp_n*(n+1-i))%MOD;
        tmp_d=(tmp_d*i)%MOD;
        ans=tmp_n*mod_pow(tmp_d,MOD-2);
    }

    return ans;    
}

int main() {
    ULL n;
    ULL n_tmp;
    ULL a;
    ULL b;
    ULL ans=1;

    scanf("%llu %llu %llu", &n, &a, &b);
    ans=mod_pow(2,n);
    ans--;
    ULL tmp_nd;
    tmp_nd=comb_s(n,a);
    ans=(ans-tmp_nd)%MOD;
    while(ans<0){
        ans+=MOD;
    }
    //printf("%llu ", ans);

    tmp_nd=comb_s(n,b);
    ans=(ans-tmp_nd)%MOD;
    while(ans<0){
        ans+=MOD;
    }
    //printf("%llu\n", ans);

    printf("%llu\n", ans);

    return 0;
}

