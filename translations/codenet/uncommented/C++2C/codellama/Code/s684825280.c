#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE (1e5 * 2) + 13

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int cnt[SIZE];
    memset(cnt, 0, sizeof(cnt));
    int a[SIZE];
    int a_size = 0;
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0)
            a[a_size++] = cnt[i];
    }
    int ans = 0;
    qsort(a, a_size, sizeof(int), cmp);
    int m = a_size - k;
    for(int i = 0; i < m; ++i){
        ans += a[i];
    }
    printf("%d\n", ans);
    
    return 0;
}

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

