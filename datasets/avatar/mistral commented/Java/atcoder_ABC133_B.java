
import java.lang.Math ;  // Importing Math library for square root calculation
import java.util.Scanner ;  // Importing Scanner library for user input

public class Main {
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;  // Creating a new Scanner object for user input
        
        // Reading the number of vectors N and their dimensions D from user input
        int N = sc.nextInt ( ) ;
        int D = sc.nextInt ( ) ;

        // Creating a 2D integer array 'vectors' of size N x D to store the vectors
        int [ ] [ ] vectors = new int [ N ] [ D ] ;

        // Reading the components of each vector from user input and storing it in the 'vectors' array
        for ( int i = 0 ; i < N ; i ++ ) {
            for ( int j = 0 ; j < D ; j ++ ) {
                vectors [ i ] [ j ] = sc.nextInt ( ) ;
            }
        }

        // Initializing the answer variable to 0
        int answer = 0 ;

        // Iterating through all pairs of vectors (i, j) where i < j
        for ( int i = 0 ; i < N - 1 ; i ++ ) {
            for ( int j = i + 1 ; j < N ; j ++ ) {

                // Calculating the Euclidean distance between the vectors i and j
                int dist = 0 ;
                for ( int d = 0 ; d < D ; d ++ ) {
                    int x = vectors [ i ] [ d ] - vectors [ j ] [ d ] ;  // Difference between corresponding components
                    dist += ( x * x ) ;  // Squaring the difference and adding to the distance
                }

                // Calculating the square root of the distance and checking if it is a perfect square
                double sq = Math.sqrt ( dist ) ;
                answer += ( Math.abs ( sq - Math.floor ( sq ) ) < 0.001 ? 1 : 0 ) ;
            }
        }

        // Printing the final answer
        System.out.println ( answer ) ;
    }
}