import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int m = sc.nextInt ( );
        int [ ] [ ] li = new int [ m ] [ n + 1 ];
        for ( int i = 0 ; i < m ; i ++ ) {
            for ( int j = 1 ; j <= n ; j ++ ) {
                li [ i ] [ j ] = sc.nextInt ( );
            }
        }
        int [ ] p = new int [ n + 1 ];
        for ( int i = 1 ; i <= n ; i ++ ) {
            p [ i ] = sc.nextInt ( );
        }
        Set < Integer > q = new HashSet < > ( );
        for ( int i = 1 ; i <= n ; i ++ ) {
            q.add ( i );
        }
        Set < Integer > r = new HashSet < > ( );
        for ( int i = 1 ; i <= n ; i ++ ) {
            r.add ( i );
        }
        Set < Integer > v = new HashSet < > ( r );
        v.removeAll ( q );
        int ans = 0;
        for ( int i = 0 ; i <= q.size ( ) ; i ++ ) {
            for ( Set < Integer > s : Sets.powerSet ( q ) ) {
                if ( s.size ( )!= i ) {
                    continue;
                }
                for ( int j = 0 ; j < m ; j ++ ) {
                    if ( ( s.size ( ) & 1 )!= p [ j ] ) {
                        break;
                    }
                    if (!s.containsAll ( Arrays.asList ( li [ j ] ) ) ) {
                        break;
                    }
                } else {
                    ans += Math.pow ( 2, v.size ( ) );
                }
            }
        }
        System.out.println ( ans );
    }
}
