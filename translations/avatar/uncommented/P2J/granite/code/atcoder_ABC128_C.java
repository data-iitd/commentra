
import java. util. * ;
class atcoder_ABC128_C {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System. in ) ;
        int n = sc.nextInt ( ) ;
        int m = sc.nextInt ( ) ;
        int [ ] [ ] li = new int [ m ] [ n - 1 ] ;
        for ( int i = 0 ; i < m ; i ++ ) {
            for ( int j = 0 ; j < n - 1 ; j ++ ) {
                li [ i ] [ j ] = sc.nextInt ( ) ;
            }
        }
        int [ ] p = new int [ m ] ;
        for ( int i = 0 ; i < m ; i ++ ) {
            p [ i ] = sc.nextInt ( ) ;
        }
        Set < Integer > q = new HashSet < Integer > ( ) ;
        for ( int i = 0 ; i < m ; i ++ ) {
            for ( int j = 0 ; j < n - 1 ; j ++ ) {
                if ( li [ i ] [ j ] == 1 ) {
                    q. add ( j + 1 ) ;
                }
            }
        }
        Set < Integer > r = new HashSet < Integer > ( ) ;
        for ( int i = 1 ; i <= n ; i ++ ) {
            r. add ( i ) ;
        }
        r. removeAll ( q ) ;
        int ans = 0 ;
        for ( int i = 0 ; i <= q. size ( ) ; i ++ ) {
            for ( Integer s : itertools. combinations ( q, i ) ) {
                boolean flag = true ;
                for ( int j = 0 ; j < m ; j ++ ) {
                    Set < Integer > t = new HashSet < Integer > ( s ) ;
                    for ( int k = 0 ; k < n - 1 ; k ++ ) {
                        if ( t. contains ( li [ j ] [ k ] ) ) {
                            t. remove ( li [ j ] [ k ] ) ;
                        }
                    }
                    if ( t. size ( ) % 2!= p [ j ] ) {
                        flag = false ;
                        break ;
                    }
                }
                if ( flag ) {
                    ans += ( int ) Math. pow ( 2, r. size ( ) ) ;
                }
            }
        }
        System. out. println ( ans ) ;
    }
}
