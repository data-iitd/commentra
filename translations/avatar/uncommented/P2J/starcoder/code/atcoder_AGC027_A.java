import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );
        int x = sc.nextInt ( );
        int [ ] a = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ )
            a [ i ] = sc.nextInt ( );
        Arrays.sort ( a );
        int ans = 0;
        if ( a [ 0 ] > x ) {
            System.out.println ( 0 );
            return;
        }
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( a [ i ] > x ) {
                x = 0;
                break;
            }
            x -= a [ i ];
            ans += 1;
        }
        if ( x!= 0 )
            ans -= 1;
        System.out.println ( ans );
    }
}
