
import java.util.Arrays ; 
import java.util.* ; 
import java.io.PrintWriter ; 
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Initialize Scanner to read input from standard input
        Scanner input = new Scanner ( System.in ) ; 
        // Initialize PrintWriter to write output to standard output
        PrintWriter out = new PrintWriter ( System.out ) ; 
        
        // Read the number of elements
        int n = input.nextInt ( ) ; 
        
        // Initialize a 2D array to store the elements
        int [ ] [ ] vec = new int [ n ] [ 4 ] ; 
        
        // Read the elements into the 2D array
        for ( int i = 0 ; i < n ; i ++ ) { 
            vec [ i ] [ 0 ] = input.nextInt ( ) ; 
            vec [ i ] [ 1 ] = input.nextInt ( ) ; 
            vec [ i ] [ 2 ] = input.nextInt ( ) ; 
            vec [ i ] [ 3 ] = input.nextInt ( ) ; 
        }
        
        // Initialize variables to store the best index and its price
        int ans = 500 ; 
        int ansprice = 20000 ; 
        
        // Loop through each element to find the best one
        for ( int i = 0 ; i < n ; i ++ ) { 
            int fl = 1 ; // Flag to check if the element is dominated
            
            // Compare the current element with every other element
            for ( int j = 0 ; j < n ; j ++ ) { 
                if ( vec [ i ] [ 0 ] < vec [ j ] [ 0 ] && vec [ i ] [ 1 ] < vec [ j ] [ 1 ] && vec [ i ] [ 2 ] < vec [ j ] [ 2 ] ) { 
                    fl = 0 ; // The element is dominated
                } 
            }
            
            // If the element is not dominated, check its price
            if ( fl == 1 ) { 
                if ( vec [ i ] [ 3 ] < ansprice ) { 
                    ansprice = vec [ i ] [ 3 ] ; // Update the minimum price
                    ans = i + 1 ; // Update the best index
                } 
            } 
        }
        
        // Output the index of the best element
        System.out.println ( ans ) ; 
        
        // Close the PrintWriter to release resources
        out.close ( ) ; 
    } 
}