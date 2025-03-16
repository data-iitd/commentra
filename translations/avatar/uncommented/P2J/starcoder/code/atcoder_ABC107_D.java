import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int m = n * ( n + 1 ) / 4;
        int [ ] a = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ )
            a [ i ] = sc.nextInt ( );
        Arrays.sort ( a );
        int [ ] d = new int [ a.length + 1 ];
        for ( int i = 0 ; i < a.length ; i ++ )
            d [ a [ i ] ] = i;
        int [ ] b = new int [ n + 1 ];
        for ( int i = 0 ; i < n ; i ++ )
            b [ i + 1 ] = b [ i ] + ( a [ i ] >= m? 2 : 1 );
        int c = Math.min ( b [ n ], 0 );
        for ( int i = 0 ; i < n ; i ++ )
            b [ i + 1 ] -= c;
        BIT bit = new BIT ( Math.max ( b ) + 2 );
        int ans = 0;
        for ( int x : b )
            ans += bit.bitsum ( x + 1 );
        System.out.println ( a [ ans >= m? 0 : 1 ] );
    }
}
class BIT {
    int [ ] tree;
    int size;
    int depth;
    public BIT ( int N ) {
        size = N;
        tree = new int [ N + 1 ];
        depth = N.bitLength ( );
    }
    public int _bitsum ( int i ) {
        int ret = 0;
        while ( i > 0 ) {
            ret += tree [ i ];
            i -= i & - i;
        }
        return ret;
    }
    public int bitsum ( int l, int r ) {
        return _bitsum ( r ) - _bitsum ( l );
    }
    public void bitadd ( int i, int x ) {
        i += 1;
        while ( i <= size ) {
            tree [ i ] += x;
            i += i & - i;
        }
    }
}
