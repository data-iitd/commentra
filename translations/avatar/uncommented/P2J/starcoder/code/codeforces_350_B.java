import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int [ ] t = new int [ n + 1 ];
        int [ ] a = new int [ n + 1 ];
        for ( int i = 1 ; i <= n ; i ++ ) {
            t [ i ] = sc.nextInt ( );
            a [ i ] = sc.nextInt ( );
        }
        int [ ] ans = new int [ n + 1 ];
        int [ ] cnt = new int [ n + 1 ];
        for ( int i = 1 ; i <= n ; i ++ ) {
            cnt [ a [ i ] ] += 1;
        }
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( t [ i ] == 1 ) {
                int [ ] crt = new int [ n + 1 ];
                int x = a [ i ];
                while ( cnt [ x ] == 1 ) {
                    crt [ x ] = 1;
                    x = a [ x ];
                }
                if ( crt [ i ] == 1 ) {
                    ans [ i ] = 1;
                }
            }
        }
        int cnt = 0;
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( ans [ i ] == 1 ) {
                cnt += 1;
            }
        }
        System.out.println ( cnt );
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( ans [ i ] == 1 ) {
                System.out.print ( i + " " );
            }
        }
    }
}
