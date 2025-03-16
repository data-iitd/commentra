import java.util.*;
import java.io.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        if ( n == 1 ) {
            System.out.println ( 0 );
            return;
        }
        int [ ] arr = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ ) {
            arr [ i ] = sc.nextInt ( );
        }
        int ans = 0;
        for ( int i = 0 ; i < n ; i ++ ) {
            int x = arr [ i ];
            for ( int j = 1 ; j < 99999999 ; j ++ ) {
                if ( x >= j ) {
                    x -= j;
                    ans += 1;
                } else {
                    break;
                }
            }
        }
        System.out.println ( ans );
    }
}
