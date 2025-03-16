import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int m = sc.nextInt ( );
        boolean [ ] b = new boolean [ 2 * n + 1 ];
        b [ 0 ] = b [ 2 * n ] = false;
        for ( int i = 0 ; i < m ; i ++ ) {
            int r = sc.nextInt ( );
            int c = sc.nextInt ( );
            b [ r - 1 ] = b [ 2 * n - c ] = false;
        }
        int count = 0;
        for ( int i = 0 ; i < 2 * n + 1 ; i ++ )
            if ( b [ i ] ) count ++;
        System.out.println ( count );
    }
}
