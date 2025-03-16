#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define SIZE (1e5 * 2) + 13

int cnt[SIZE];
int* a;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    int size_a = 0;
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0)
            size_a++;
    }
    a = (int*)malloc(size_a * sizeof(int));
    int j = 0;
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0){
            a[j++] = cnt[i];
        }
    }
    int ans = 0;
    std::sort(a, a + size_a);
    int m = size_a - k;
    for(int i = 0; i < m; ++i){
        ans += a[i];
    }
    printf("%d\n", ans);
    free(a);
}

