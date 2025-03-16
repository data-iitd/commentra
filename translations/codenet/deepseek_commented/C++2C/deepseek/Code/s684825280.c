#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define SIZE (1e5 * 2) + 13

int cnt[SIZE];
int a[SIZE];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    
    int j = 0;
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0)
            a[j++] = cnt[i];
    }
    
    qsort(a, j, sizeof(int), (int (*)(const void *, const void *))compare);
    
    int ans = 0;
    int m = j - k;
    for(int i = 0; i < m; ++i){
        ans += a[i];
    }
    
    printf("%d\n", ans);
}

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

