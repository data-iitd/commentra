import java.util.*;
import java.io.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        int K = sc.nextInt ( );
        int [ ] graph = new int [ N ];
        for ( int i = 0 ; i < N ; i ++ ) {
            graph [ i ] = sc.nextInt ( );
        }
        int [ ] dp = new int [ N ];
        Arrays.fill ( dp, 1 );
        for ( int i = 0 ; i < N ; i ++ ) {
            for ( int j = 0 ; j < graph [ i ] ; j ++ ) {
                dp [ i ] = ( dp [ i ] * dp [ graph [ i ] ] ) % 1000000007;
            }
        }
        int ans = 1;
        for ( int i = 0 ; i < N ; i ++ ) {
            if ( i == 0 ) {
                ans = ( ans * dp [ i ] ) % 1000000007;
            } else {
                ans = ( ans * dp [ i ] ) % 1000000007;
            }
        }
        System.out.println ( ans );
    }
}
