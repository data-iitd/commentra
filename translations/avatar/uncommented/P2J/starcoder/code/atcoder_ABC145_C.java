import java.util.*;
public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        int [ ] x = new int [ N ];
        int [ ] y = new int [ N ];
        for ( int i = 0 ; i < N ; i ++ ) {
            x [ i ] = sc.nextInt ( );
            y [ i ] = sc.nextInt ( );
        }
        solve ( N, x, y );
    }
    public static void solve ( int N, int [ ] x, int [ ] y ) {
        List < Integer > indices = new ArrayList < > ( );
        for ( int i = 0 ; i < N ; i ++ ) {
            indices.add ( i );
        }
        List < List < Integer > > permutations = new ArrayList < > ( );
        permutations.add ( indices );
        while ( true ) {
            List < Integer > new_permutation = new ArrayList < > ( );
            boolean found = false;
            for ( List < Integer > permutation : permutations ) {
                for ( int i = 0 ; i < N - 1 ; i ++ ) {
                    int f = permutation.get ( i );
                    int t = permutation.get ( i + 1 );
                    int distance = ( ( x [ t ] - x [ f ] ) * ( x [ t ] - x [ f ] ) + ( y [ t ] - y [ f ] ) * ( y [ t ] - y [ f ] ) ) ;
                    new_permutation.add ( f );
                    new_permutation.add ( t );
                }
                found = true;
            }
            if (! found ) {
                break;
            }
            permutations.add ( new_permutation );
        }
        double result = 0;
        for ( List < Integer > permutation : permutations ) {
            double total_distance = 0;
            for ( int i = 0 ; i < N - 1 ; i ++ ) {
                int f = permutation.get ( i );
                int t = permutation.get ( i + 1 );
                double distance = Math.sqrt ( ( x [ t ] - x [ f ] ) * ( x [ t ] - x [ f ] ) + ( y [ t ] - y [ f ] ) * ( y [ t ] - y [ f ] ) ) ;
                total_distance += distance;
            }
            result += total_distance;
        }
        result /= permutations.size ( );
        System.out.println ( result );
    }
}
