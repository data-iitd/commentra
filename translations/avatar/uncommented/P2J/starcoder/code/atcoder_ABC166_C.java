import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int m = sc.nextInt ( );
        int [ ] p = new int [ n + 1 ];
        int [ ] h = new int [ n + 1 ];
        for ( int i = 1 ; i <= n ; i ++ ) {
            p [ i ] = i;
            h [ i ] = sc.nextInt ( );
        }
        HashMap < Integer, ArrayList < Integer > > path = new HashMap < > ( );
        for ( int i = 0 ; i < m ; i ++ ) {
            int a = sc.nextInt ( );
            int b = sc.nextInt ( );
            if (!path.containsKey ( a ) ) {
                path.put ( a, new ArrayList < > ( ) );
            }
            if (!path.containsKey ( b ) ) {
                path.put ( b, new ArrayList < > ( ) );
            }
            path.get ( a ).add ( b );
            path.get ( b ).add ( a );
        }
        int c = 0;
        for ( int i = 1 ; i <= n ; i ++ ) {
            boolean f = false;
            for ( int j : path.get ( i ) ) {
                if ( h [ i ] <= h [ j ] ) {
                    f = true;
                    break;
                }
            }
            if (!f ) {
                c += 1;
            }
        }
        System.out.println ( c );
    }
}
