
import java.util.*;

public class Main {

    public static void main ( String [ ] args ) {
        // Read the number of points N
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        
        // Initialize lists for x and y coordinates
        int [ ] x = new int [ N ];
        int [ ] y = new int [ N ];
        
        // Read the x and y coordinates for each point
        for ( int i = 0 ; i < N ; i++ ) {
            x [ i ] = sc.nextInt ( );
            y [ i ] = sc.nextInt ( );
        }
        
        // Call the solve function with the input values
        solve ( N, x, y );
    }
    
    public static void solve ( int N, int [ ] x, int [ ] y ) {
        // Generate a list of indices from 0 to N-1
        List < Integer > indices = new ArrayList < > ( );
        for ( int i = 0 ; i < N ; i++ ) {
            indices.add ( i );
        }
        
        // Generate all permutations of the indices
        List < List < Integer > > permutations = new ArrayList < > ( );
        for ( List < Integer > p : new Permutations ( indices ) ) {
            permutations.add ( p );
        }
        
        // Initialize a list to store the total distances for each permutation
        List < Double > distances = new ArrayList < > ( );
        
        // Iterate over each permutation
        for ( List < Integer > permutation : permutations ) {
            // Initialize the total distance for the current permutation
            double total_distance = 0;
            
            // Calculate the distance between consecutive points in the permutation
            for ( int i = 0 ; i < N - 1 ; i++ ) {
                int f = permutation.get ( i );
                int t = permutation.get ( i + 1 );
                double distance = Math.sqrt ( Math.pow ( x [ t ] - x [ f ], 2 ) + Math.pow ( y [ t ] - y [ f ], 2 ) );
                total_distance += distance;
            }
            
            // Append the total distance of the current permutation to the distances list
            distances.add ( total_distance );
        }
        
        // Calculate the average distance by averaging all stored distances
        double result = 0;
        for ( double distance : distances ) {
            result += distance;
        }
        result /= distances.size ( );
        
        // Print the result
        System.out.println ( result );
    }
    
    public static class Permutations < T > extends AbstractList < List < T > > {
        private final List < T > elements;
        
        public Permutations ( List < T > elements ) {
            this.elements = elements;
        }
        
        @Override
        public List < T > get ( int index ) {
            return new ArrayList < > ( elements );
        }
        
        @Override
        public int size ( ) {
            return factorial ( elements.size ( ) );
        }
        
        private static < T > int factorial ( int n ) {
            int result = 1;
            for ( int i = 2 ; i <= n ; i++ ) {
                result *= i;
            }
            return result;
        }
    }
}

