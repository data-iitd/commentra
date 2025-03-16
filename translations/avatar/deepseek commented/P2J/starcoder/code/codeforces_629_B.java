
import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        int [ ] m = new int [ N ];
        int [ ] f = new int [ N ];
        for ( int i = 0 ; i < N ; i ++ ) {
            String [ ] x = sc.next ( ).split ( " " );
            int a = Integer.parseInt ( x [ 1 ] );
            int b = Integer.parseInt ( x [ 2 ] ) + 1;
            if ( x [ 0 ].equals ( "M" ) ) {
                m [ a ] += 2;
                m [ b ] -= 2;
            } else {
                f [ a ] += 2;
                f [ b ] -= 2;
            }
        }
        int a = 0, b = 0, c = 0;
        for ( int i = 0 ; i < N ; i ++ ) {
            a += m [ i ];
            b += f [ i ];
            c = Math.min ( a, b );
        }
        System.out.println ( c );
    }
}

