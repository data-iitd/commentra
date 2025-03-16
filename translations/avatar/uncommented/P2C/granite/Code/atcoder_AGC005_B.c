
#include <stdio.h>
#include <stdlib.h>

int root(int *par, int x){
    return x == par[x]? x : (par[x] = root(par, par[x]));
}

int same(int *par, int x, int y){
    return root(par, x) == root(par, y);
}

void unite(int *par, int *rank, int *size, int x, int y){
    x = root(par, x);
    y = root(par, y);
    if(x!= y){
        if(rank[x] < rank[y]){
            par[x] = y;
            size[y] += size[x];
        }else{
            par[y] = x;
            size[x] += size[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int *par = (int *)malloc(sizeof(int) * n);
    int *rank = (int *)malloc(sizeof(int) * n);
    int *size = (int *)malloc(sizeof(int) * n);
    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        par[i] = i;
        rank[i] = 1;
        size[i] = 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[a[i] - 1] = i;
    }
    long long c = 0;
    for(int k = n - 1; k >= 0; k--){
        int l = 1, r = 1;
        if(k > 0 && a[k - 1] > a[k]){
            l += size[root(par, k - 1)];
            unite(par, rank, size, k - 1, k);
        }
        if(k + 1 < n && a[k + 1] > a[k]){
            r += size[root(par, k + 1)];
            unite(par, rank, size, k + 1, k);
        }
        c += (long long)l * r * a[k];
    }
    printf("%lld\n", c);
    free(par);
    free(rank);
    free(size);
    free(a);
    free(b);
    return 0;
}
