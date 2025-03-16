#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE (1e5 * 2 + 13)

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *cnt = (int *)calloc(SIZE, sizeof(int));
    int *a = (int *)calloc(SIZE, sizeof(int));
    int ans = 0;

    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0)
            a[i] = cnt[i];
    }

    qsort(a, SIZE, sizeof(int), compare);

    int m = SIZE - k;
    for(int i = 0; i < m; ++i){
        ans += a[i];
    }

    printf("%d\n", ans);

    free(cnt);
    free(a);

    return 0;
}

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

