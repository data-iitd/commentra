import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        int [ ] S = new int [ N ];
        for ( int i = 0 ; i < N ; i ++ ) {
            S [ i ] = sc.nextInt ( );
        }
        Arrays.sort ( S, Collections.reverseOrder ( ) );
        boolean [ ] flag = new boolean [ N ];
        List < Integer > cur = new ArrayList < > ( );
        cur.add ( S [ 0 ] );
        flag [ 0 ] = false;
        for ( int i = 0 ; i < N ; i ++ ) {
            int j = 0;
            int jM = cur.size ( );
            for ( int k = 0 ; k < N ; k ++ ) {
                if (! flag [ k ] && S [ k ] < cur.get ( j ) ) {
                    cur.add ( S [ k ] );
                    j += 1;
                    flag [ k ] = false;
                    if ( j == jM ) {
                        break;
                    }
                }
            } else {
                System.out.println ( "No" );
                return;
            }
            Collections.sort ( cur, Collections.reverseOrder ( ) );
        }
        System.out.println ( "Yes" );
    }
}
