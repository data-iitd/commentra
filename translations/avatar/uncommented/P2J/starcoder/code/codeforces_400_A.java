import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int t = sc.nextInt ( );
        while ( t-- > 0 ) {
            int n = sc.nextInt ( );
            int [ ] arr = new int [ n ];
            for ( int i = 0 ; i < n ; i++ ) arr [ i ] = sc.nextInt ( );
            int [ ] ans = new int [ 100 ];
            int [ ] cnt = new int [ 100 ];
            for ( int i = 0 ; i < n ; i++ ) {
                if ( arr [ i ] == 0 ) ans [ 0 ]++;
                else ans [ arr [ i ] ]++;
            }
            for ( int i = 1 ; i < 100 ; i++ ) {
                if ( ans [ i ] == 0 ) continue;
                for ( int j = i ; j < 100 ; j += i ) {
                    cnt [ j ] += ans [ i ];
                }
            }
            int [ ] ans2 = new int [ 100 ];
            for ( int i = 1 ; i < 100 ; i++ ) {
                if ( cnt [ i ] == 0 ) continue;
                ans2 [ cnt [ i ] ]++;
            }
            int [ ] ans3 = new int [ 100 ];
            int k = 0;
            for ( int i = 0 ; i < 100 ; i++ ) {
                if ( ans2 [ i ] == 0 ) continue;
                ans3 [ k ] = i;
                k++;
            }
            System.out.print ( ans3 [ 0 ] );
            for ( int i = 1 ; i < ans3 [ 0 ] ; i++ ) System.out.print ( " " + ans3 [ i ] );
            System.out.println ( );
        }
    }
}
