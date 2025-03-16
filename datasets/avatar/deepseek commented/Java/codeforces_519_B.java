
import java.util.* ; 
import java.io.* ; 

public class Main { 
    public static void main ( String args [ ] ) throws IOException { 
        // Create a Scanner object to read input from the standard input stream
        Scanner sc = new Scanner ( System.in ) ; 
        
        // Read the number of elements
        int n = sc.nextInt ( ) ; 
        
        // Initialize sums of subsets
        int a = 0 , b = 0 , c = 0 ; 
        
        // Sum all n elements
        for ( int i = 0 ; i < n ; i ++ ) 
            a += sc.nextInt ( ) ; 
        
        // Sum n-1 elements
        for ( int i = 0 ; i < n - 1 ; i ++ ) 
            b += sc.nextInt ( ) ; 
        
        // Sum n-2 elements
        for ( int i = 0 ; i < n - 2 ; i ++ ) 
            c += sc.nextInt ( ) ; 
        
        // Calculate the differences
        int x = a - b ; 
        int y = b - c ; 
        
        // Output the results
        System.out.println ( x ) ; 
        System.out.println ( y ) ; 
    } 
}

