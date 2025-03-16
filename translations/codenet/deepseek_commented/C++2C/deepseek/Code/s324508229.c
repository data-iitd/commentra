#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n, ii, a, b;
    scanf("%d", &n);
    long long cnt[10][10] = {0};
    for(int i = 0; i < 100; i++){
        cnt[i % 10][i / 10] = 0;
    }
    for(int i = 1; i <= n; i++){
        b = i % 10;
        a = i;
        while(a >= 10){
            a /= 10;
        }
        cnt[a][b]++;
    }
    long long ans = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    printf("%lld\n", ans);
}
