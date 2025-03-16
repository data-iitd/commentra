
#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

typedef struct UnionFindTree {
    int n ;
    int *par ;
    int *rank ;
} UnionFindTree ;

void doIt(UnionFindTree *utf) {
    int n = utf->n ;
    int m = 0 ;
    scanf("%d", &m) ;
    for ( int i = 0 ; i < m ; i ++ ) {
        int x, y, z ;
        scanf("%d%d%d", &x, &y, &z) ;
        x -- ;
        y -- ;
        utf->unite(x, y) ;
    }
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
        if ( utf->par[i] == i ) {
            cnt ++ ;
        }
    }
    printf("%d\n", cnt) ;
}

void init(UnionFindTree *utf, int n) {
    utf->n = n ;
    utf->par = (int *) malloc(sizeof(int) * n) ;
    utf->rank = (int *) malloc(sizeof(int) * n) ;
    for ( int i = 0 ; i < n ; i ++ ) {
        utf->par[i] = i ;
        utf->rank[i] = 0 ;
    }
}

int find(UnionFindTree *utf, int x) {
    if (utf->par[x] == x) {
        return x ;
    } else {
        return utf->par[x] = find(utf, utf->par[x]) ;
    }
}

void unite(UnionFindTree *utf, int x, int y) {
    x = find(utf, x) ;
    y = find(utf, y) ;
    if (x == y) return ;
    if (utf->rank[x] < utf->rank[y]) {
        utf->par[x] = y ;
    } else {
        utf->par[y] = x ;
        if (utf->rank[x] == utf->rank[y]) utf->rank[x] ++ ;
    }
}

int main(void) {
    int n ;
    scanf("%d", &n) ;
    UnionFindTree utf ;
    init(&utf, n) ;
    doIt(&utf) ;
    return 0 ;
}

