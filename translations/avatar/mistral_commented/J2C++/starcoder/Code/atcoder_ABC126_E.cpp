
#include <bits/stdc++.h>
using namespace std ;

class Main {
public:
    int MOD = 1000000007 ;
    void doIt() {
        int n = 0 ;
        cin >> n ;
        UnionFindTree utf(n) ;
        int m = 0 ;
        cin >> m ;
        for ( int i = 0 ; i < m ; i ++ ) {
            int x = 0, y = 0, z = 0 ;
            cin >> x >> y >> z ;
            utf.unite(x - 1, y - 1) ;
        }
        int cnt = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( utf.par[i] == i ) {
                cnt ++ ;
            }
        }
        cout << cnt << endl ;
    }

    class UnionFindTree {
    public:
        int n ;
        int *par ;
        int *rank ;

        UnionFindTree(int n) {
            this->n = n ;
            par = new int[n] ;
            rank = new int[n] ;
            for ( int i = 0 ; i < n ; i ++ ) {
                par[i] = i ;
                rank[i] = 0 ;
            }
        }

        int find(int x) {
            if (par[x] == x) {
                return x ;
            } else {
                return par[x] = find(par[x]) ;
            }
        }

        void unite(int x, int y) {
            x = find(x) ;
            y = find(y) ;
            if (x == y) return ;
            if (rank[x] < rank[y]) {
                par[x] = y ;
            } else {
                par[y] = x ;
                if (rank[x] == rank[y]) rank[x]++ ;
            }
        }

        bool same(int x, int y) {
            return find(x) == find(y) ;
        }
    } ;

    Main() {
        doIt() ;
    }
} ;

int main() {
    Main m ;
    return 0 ;
}

