#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<limits.h>
#include<stdbool.h>

#define SIZE (1e5 * 2) + 13

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int cnt[SIZE];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int a[SIZE];
    int ans = 0;
    int m = 0;
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0){
            a[m++] = cnt[i];
        }
    }
    sort(a, a + m);
    m -= k;
    for(int i = 0; i < m; ++i){
        ans += a[i];
    }
    printf("%d\n", ans);
}

