#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

#define MOD 1000000007

int mod_pow(int x, int n){
    int ans = 1;
    while(n>0){
        if((n&1)==1){
            ans = ans * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return ans;
}

int comb_s(int n, int r){
    int tmp_n=1;
    int tmp_d=1;
    int ans;
    for(int i=1; i<=r; i++){
        tmp_n=(tmp_n*(n+1-i))%MOD;
        tmp_d=(tmp_d*i)%MOD;
        ans=tmp_n*mod_pow(tmp_d,MOD-2);
    }

    return ans;    
}

int main() {
    int n;
    int n_tmp;
    int a;
    int b;
    int ans=1;

    scanf("%d %d %d", &n, &a, &b);
    ans=mod_pow(2,n);
    ans--;
    int tmp_nd;
    tmp_nd=comb_s(n,a);
    ans=(ans-tmp_nd)%MOD;
    while(ans<0){
        ans+=MOD;
    }
    //printf("%d %d\n", ans, tmp_ans);

    tmp_nd=comb_s(n,b);
    ans=(ans-tmp_nd)%MOD;
    //printf("%d %d\n", ans, tmp_ans);
    while(ans<0){
        ans+=MOD;
    }

    printf("%d\n", ans);

    return 0;
}

