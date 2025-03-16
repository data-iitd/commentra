import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int k = sc.nextInt ( );
        int l = sc.nextInt ( );
        int r = sc.nextInt ( );
        int sa = sc.nextInt ( );
        int sk = sc.nextInt ( );
        int [ ] ans = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ ) {
            ans [ i ] = ( r - l + 1 ) / ( n - i ) * ( k - i ) + ( r - l + 1 ) % ( n - i ) * ( sa - sk ) / ( n - i );
        }
        for ( int i = 0 ; i < n ; i ++ ) {
            System.out.print ( ans [ i ] + " " );
        }
    }
}
