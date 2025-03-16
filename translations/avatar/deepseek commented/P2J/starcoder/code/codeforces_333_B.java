
import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int m = sc.nextInt ( );
        int [ ] b = new int [ 2 * n ];
        for ( int i = 0 ; i < 2 * n ; i ++ ) b [ i ] = 1;
        for ( int i = 0 ; i < m ; i ++ ) {
            int r = sc.nextInt ( );
            int c = sc.nextInt ( );
            b [ r - 1 ] = b [ n + c - 1 ] = 0;
        }
        if ( n % 2 == 1 && b [ n / 2 ] == 1 && b [ n + n / 2 ] == 1 ) b [ n / 2 ] = 0;
        System.out.println ( Arrays.stream ( b ).sum ( ) );
    }
}

