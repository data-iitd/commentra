
import java.util.* ; 

public class Main {
    int INF = Integer.MAX_VALUE ; 

    public static void main ( String [ ] args ) {
        new Main ( ).solve ( ) ;
    }

    void solve ( ) {
        // Read the number of points N and the target value X
        Scanner sc = new Scanner ( System.in ) ;
        int N = sc.nextInt ( ) ;
        long X = sc.nextLong ( ) ;

        // Initialize an array to store the positions of N points
        long [ ] x = new long [ N ] ;
        long [ ] xsum = new long [ N + 1 ] ;

        // Read the positions of the points into the array x and calculate the cumulative sum
        for ( int i = 0 ; i < N ; i ++ ) {
            x [ i ] = sc.nextInt ( ) ;
            xsum [ i + 1 ] = xsum [ i ] + x [ i ] ;
        }

        // Initialize ans with a value calculated using the total sum of positions and the given X value
        long ans = X * N + 5 * xsum [ N ] ;

        // Iterate over possible values of i, which represents the number of points to be removed
        for ( int i = 1 ; i < N ; i ++ ) {
            long cost = X * i + 5 * ( xsum [ N ] - xsum [ N - i ] ) ;

            // For each value of i, calculate the cost of removing i points and update ans if a better cost is found
            for ( int j = 5 , k = N - i ; k >= 0 ; j += 2 , k -= i ) {
                if ( cost > ans ) {
                    break ;
                }
                cost += j * ( xsum [ k ] - xsum [ Math.max ( k - i , 0 ) ] ) ;
            }
            ans = Math.min ( ans , cost ) ;
        }

        // Print the minimum cost found
        System.out.println ( ans + N * X ) ;
    }
}
