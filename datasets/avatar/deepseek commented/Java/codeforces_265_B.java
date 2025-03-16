import java.io.* ; // Importing packages for input/output operations and utility classes
import java.util.* ; // Importing utility classes

public class Main {
    public static void main ( String [ ] args ) {
        Scanner scn = new Scanner ( System.in ) ; // Initialize the Scanner object to read input
        int n = scn.nextInt ( ) ; // Read the size of the array
        int [ ] arr = new int [ n ] ; // Initialize the array of size n
        
        // Read n integers into the array
        for ( int i = 0 ; i < arr.length ; i ++ ) {
            arr [ i ] = scn.nextInt ( ) ;
        }
        
        // Initialize ans with the value of the first element plus 1
        int ans = arr [ 0 ] + 1 ;
        
        // Iterate through the array and update ans
        for ( int i = 1 ; i < arr.length ; i ++ ) {
            ans += Math.abs ( arr [ i ] - arr [ i - 1 ] ) + 2 ;
        }
        
        // Print the final value of ans
        System.out.println ( ans ) ;
    }
}