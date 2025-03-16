
import java.util.*;

public class Main {

    public static void main ( String [ ] args ) {

        Scanner sc = new Scanner ( System.in );

        int n = sc.nextInt ( );
        int [ ] a = new int [ n ];
        for ( int i = 0 ; i < n ; i ++ ) {
            a [ i ] = sc.nextInt ( );
        }

        if ( sum ( a ) % ( n * ( n + 1 ) / 2 )!= 0 ) {
            System.out.println ( "NO" );
        } else {
            int k = sum ( a ) / ( n * ( n + 1 ) / 2 );
            a = Arrays.copyOf ( a, n + 1 );
            a [ n ] = a [ 0 ];
            if ( sum ( Arrays.stream ( a ).map ( i -> ( k - i + j ) % n ).toArray ( Integer [ ]::new ) )!= 0 || sum ( Arrays.stream ( a ).map ( i -> ( k - i + j ) / n >= 0 ).toArray ( Integer [ ]::new ) )!= n ) {
                System.out.println ( "NO" );
            } else {
                System.out.println ( "YES" );
            }
        }
    }

    public static int sum ( int [ ] a ) {
        int sum = 0;
        for ( int i : a ) {
            sum += i;
        }
        return sum;
    }
}

