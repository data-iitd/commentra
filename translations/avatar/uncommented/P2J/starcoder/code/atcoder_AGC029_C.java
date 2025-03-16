import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int [ ] A = new int [ sc.nextInt ( ) ];
        for ( int i = 0 ; i < A.length ; i ++ ) A [ i ] = sc.nextInt ( );
        Arrays.sort ( A );
        int N = A.length;
        int [ ] dp = new int [ N + 1 ];
        dp [ 0 ] = A [ 0 ];
        for ( int i = 1 ; i < N ; i ++ ) {
            if ( A [ i ] <= dp [ i - 1 ] ) {
                dp [ i ] = dp [ i - 1 ];
            } else {
                dp [ i ] = A [ i ];
            }
        }
        int [ ] ans = new int [ N + 1 ];
        ans [ 0 ] = dp [ 0 ];
        for ( int i = 1 ; i < N ; i ++ ) {
            if ( dp [ i ] == ans [ i - 1 ] ) {
                ans [ i ] = ans [ i - 1 ] + 1;
            } else {
                ans [ i ] = dp [ i ];
            }
        }
        System.out.println ( ans [ N - 1 ] );
    }
}
