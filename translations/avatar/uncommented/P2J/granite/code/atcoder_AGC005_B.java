
int root ( int x ) {
    return par [ x ] == x? x : ( par [ x ] = root ( par [ x ] ) );
}
boolean same ( int x, int y ) {
    return root ( x ) == root ( y );
}
void unite ( int... z ) {
    int x = root ( z [ 0 ] ), y = root ( z [ 1 ] );
    if ( x!= y ) {
        if ( rank [ x ] < rank [ y ] ) {
            par [ x ] = y;
            size [ y ] += size [ x ];
        } else {
            par [ y ] = x;
            size [ x ] += size [ y ];
            if ( rank [ x ] == rank [ y ] ) rank [ x ] += 1;
        }
    }
}
Scanner sc = new Scanner ( System. in );
int n = sc.nextInt ( );
int[] par = new int [ n ];
int[] rank = new int [ n ];
int[] size = new int [ n ];
int[] b = new int [ n ];
for ( int i = 0 ; i < n ; i ++ ) {
    int t = sc.nextInt ( ) - 1;
    b [ t ] = i;
}
long c = 0;
for ( int k = n - 1 ; 0 <= k ; k -- ) {
    int l = 1, r = 1;
    if ( 0 < k && a [ k - 1 ] < a [ k ] ) {
        l += size [ root ( k - 1 ) ];
        unite ( k - 1, k );
    }
    if ( k + 1 < n && a [ k + 1 ] < a [ k ] ) {
        r += size [ root ( k + 1 ) ];
        unite ( k + 1, k );
    }
    c += ( long ) l * r * a [ k ];
}
System.out.println ( c );
