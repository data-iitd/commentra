
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define SIZE (1e5 * 2) + 13

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *cnt = (int *)malloc(sizeof(int) * SIZE);
    memset(cnt, 0, sizeof(int) * SIZE);

    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    int *a = (int *)malloc(sizeof(int) * SIZE);
    int len = 0;
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0){
            a[len++] = cnt[i];
        }
    }

    qsort(a, len, sizeof(int), cmpfunc);

    int ans = 0;
    int m = len - k;
    for(int i = 0; i < m; ++i){
        ans += a[i];
    }

    printf("%d\n", ans);

    free(cnt);
    free(a);

    return 0;
}

