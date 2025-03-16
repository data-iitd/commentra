#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    // Step 1: Input Reading
    LL n, c;
    scanf("%lld %lld", &n, &c);

    // Step 2: Vector Initialization
    LL *x = (LL *)malloc((n+1)*sizeof(LL));
    LL *v = (LL *)malloc((n+1)*sizeof(LL));

    // Step 3: Reading Positions and Values
    for(int i = 1; i < n+1; i++){
        scanf("%lld %lld", &x[i], &v[i]);
    }

    // Step 4: Calculate Total Value Moving Left
    LL *lefttotal = (LL *)malloc((n+1)*sizeof(LL));
    LL *maxlefttotal = (LL *)malloc((n+1)*sizeof(LL));
    for(int i = 1; i < n+1; i++){
        lefttotal[i] = lefttotal[i-1] + v[i];
    }

    // Step 5: Calculate Maximum Value Left
    for(int i = 1; i < n+1; i++){
        maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i] - x[i]);
    }

    // Step 6: Calculate Total Value Moving Right
    LL *righttotal = (LL *)malloc((n+1)*sizeof(LL));
    LL *maxrighttotal = (LL *)malloc((n+1)*sizeof(LL));
    for(int i = 1; i < n+1; i++){
        righttotal[i] = righttotal[i-1] + v[n-i+1];
    }

    // Step 7: Calculate Maximum Value Right
    for(int i = 1; i < n+1; i++){
        maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i] - (c - x[n+1-i]));
    }

    // Step 8: Calculate the Maximum Value
    LL ans = 0;
    for(int i = 1; i < n+1; i++){
        ans = max(ans, lefttotal[i] - x[i]);
        ans = max(ans, lefttotal[i] - 2*x[i] + maxrighttotal[n-i]);
        ans = max(ans, righttotal[i] - (c - x[n+1-i]));
        ans = max(ans, righttotal[i] - 2*(c - x[n+1-i]) + maxlefttotal[n-i]);
    }

    // Step 9: Output the Result
    printf("%lld\n", ans);

    // Step 10: Free Memory
    free(x);
    free(v);
    free(lefttotal);
    free(maxlefttotal);
    free(righttotal);
    free(maxrighttotal);

    return 0;
}

