
import java.util.*;
import java.io.*;

class codeforces_609_B {
    public static void main ( String [ ] args ) throws IOException {
        Scanner in = new Scanner ( System.in );
        PrintStream out = new PrintStream ( System.out );
        int n = in.nextInt ( ), m = in.nextInt ( );
        int [ ] lst = new int [ n ];
        for ( int i = 0; i < n; i ++ ) lst [ i ] = in.nextInt ( );
        Map < Integer, Integer > l = new HashMap < Integer, Integer > ( );
        for ( int i = 0; i < n; i ++ ) {
            if (! l.containsKey ( lst [ i ] ) ) l.put ( lst [ i ], 1 );
            else l.put ( lst [ i ], l.get ( lst [ i ] ) + 1 );
        }
        int res = 0;
        for ( int i = 0; i < n; i ++ ) {
            if ( l.get ( lst [ i ] ) > 1 ) {
                res += n - i - l.get ( lst [ i ] );
                l.put ( lst [ i ], l.get ( lst [ i ] ) - 1 );
            } else {
                res += n - i - 1;
            }
        }
        out.println ( res );
    }
}
