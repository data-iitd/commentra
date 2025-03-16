import java.util.*;
import java.io.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( new BufferedReader ( new InputStreamReader ( System.in ) ) );
        int n = sc.nextInt ( );
        int [ ] a = new int [ n ];
        int [ ] par = new int [ n ];
        int [ ] rank = new int [ n ];
        int [ ] size = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ ) a [ i ] = sc.nextInt ( );
        for ( int i = 0 ; i < n ; i ++ ) par [ i ] = i;
        for ( int i = 0 ; i < n ; i ++ ) rank [ i ] = 1;
        for ( int i = 0 ; i < n ; i ++ ) size [ i ] = 1;
        int [ ] b = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ ) b [ a [ i ] - 1 ] = i;
        int c = 0;
        for ( int k = n - 1 ; k >= 0 ; k -- ) {
            int l = 1;
            int r = 1;
            if ( k > 0 && a [ k - 1 ] > a [ k ] ) {
                l += size [ root ( k - 1, par, rank, size ) ];
                unite ( k - 1, k, par, rank, size );
            }
            if ( k + 1 < n && a [ k + 1 ] > a [ k ] ) {
                r += size [ root ( k + 1, par, rank, size ) ];
                unite ( k + 1, k, par, rank, size );
            }
            c += l * r * a [ k ];
        }
        System.out.println ( c );
    }
    public static int root ( int x, int [ ] par, int [ ] rank, int [ ] size ) {
        if ( par [ x ] == x ) return x;
        int y = root ( par [ x ], par, rank, size );
        size [ x ] += size [ par [ x ] ];
        par [ x ] = y;
        return y;
    }
    public static void unite ( int x, int y, int [ ] par, int [ ] rank, int [ ] size ) {
        int xRoot = root ( x, par, rank, size );
        int yRoot = root ( y, par, rank, size );
        if ( xRoot == yRoot ) return;
        if ( rank [ xRoot ] < rank [ yRoot ] ) {
            par [ xRoot ] = yRoot;
            size [ yRoot ] += size [ xRoot ];
        } else {
            par [ yRoot ] = xRoot;
            size [ xRoot ] += size [ yRoot ];
            if ( rank [ xRoot ] == rank [ yRoot ] ) rank [ xRoot ] += 1;
        }
    }
}
