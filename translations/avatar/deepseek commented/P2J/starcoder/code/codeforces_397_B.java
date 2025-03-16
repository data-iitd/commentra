
import java.util.*;

public class CodeforcesTask397B {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int t = sc.nextInt ( );
        while ( t-- > 0 ) {
            int [ ] query = new int [ 3 ];
            for ( int i = 0; i < 3; i++ ) {
                query [ i ] = sc.nextInt ( );
            }
            int k = query [ 0 ] / query [ 1 ];
            System.out.println ( k * query [ 2 ] >= query [ 0 ]? "Yes" : "No" );
        }
    }
}

