
import java.lang.Math ; 
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Read the number of vectors (N) and the dimension (D)
        int N = sc.nextInt ( ) ; 
        int D = sc.nextInt ( ) ; 
        
        // Initialize the array to store the vectors
        int [ ] [ ] vectors = new int [ N ] [ D ] ; 
        
        // Read each vector's components from the input
        for ( int i = 0 ; i < N ; i ++ ) { 
            for ( int j = 0 ; j < D ; j ++ ) { 
                vectors [ i ] [ j ] = sc.nextInt ( ) ; 
            } 
        } 
        
        // Initialize the answer variable
        int answer = 0 ; 
        
        // Calculate the Euclidean distance between each pair of vectors
        for ( int i = 0 ; i < N - 1 ; i ++ ) { 
            for ( int j = i + 1 ; j < N ; j ++ ) { 
                int dist = 0 ; 
                for ( int d = 0 ; d < D ; d ++ ) { 
                    int x = ( vectors [ i ] [ d ] - vectors [ j ] [ d ] ) ; 
                    dist += ( x * x ) ; 
                } 
                double sq = Math.sqrt ( dist ) ; 
                // Check if the distance is an integer and increment the answer if it is
                answer += ( Math.abs ( sq - Math.floor ( sq ) ) < 0.001 ? 1 : 0 ) ; 
            } 
        } 
        
        // Print the answer
        System.out.println ( answer ) ; 
    } 
}
