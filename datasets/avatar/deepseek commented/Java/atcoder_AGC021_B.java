
import java.util.Scanner ;
import java.util.Comparator ;
import java.util.Arrays ;
import java.util.List ;
import java.util.ArrayList ;

public class Main {
    public static void main ( String [ ] args ) {
        // Step 1: Read the number of points N from the input.
        Scanner scan = new Scanner ( System.in ) ;
        int N = scan.nextInt ( ) ;
        
        // Step 2: Read the coordinates of each point and store them in arrays x and y.
        int [ ] x = new int [ N ] ;
        int [ ] y = new int [ N ] ;
        for ( int i = 0 ; i < N ; ++ i ) {
            x [ i ] = scan.nextInt ( ) ;
            y [ i ] = scan.nextInt ( ) ;
        }
        
        // Step 3: For each point, calculate the angles between this point and all other points.
        for ( int i = 0 ; i < N ; ++ i ) {
            List < Double > thetas = new ArrayList < > ( ) ;
            for ( int j = 0 ; j < N ; ++ j ) {
                if ( i == j ) continue ; // Skip the point itself
                // Calculate the angle using atan2
                thetas.add ( Math.atan2 ( y [ j ] - y [ i ] , x [ j ] - x [ i ] ) ) ;
            }
            
            // Step 4: Sort the angles and add 2π to the last angle to handle the wrap-around.
            thetas.sort ( Comparator.naturalOrder ( ) ) ;
            thetas.add ( thetas.get ( 0 ) + 2 * Math.PI ) ;
            
            // Step 5: Find the maximum difference between consecutive angles, subtract π, and divide by 2π to get the fraction of the circle.
            double ans = 0 ;
            for ( int k = 0 ; k < N - 1 ; ++ k )
                ans = Math.max ( ans , thetas.get ( k + 1 ) - thetas.get ( k ) - Math.PI ) ;
            
            // Step 6: Print the result.
            System.out.println ( ans / ( Math.PI * 2 ) ) ;
        }
    }
}