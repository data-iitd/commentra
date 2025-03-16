
import java.util.Arrays ; 
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; // Initialize Scanner to read input
        int n = in.nextInt ( ) ; // Read the size of the array
        int a [ ] = new int [ n ] ; // Initialize the array of size n
        for ( int i = 0 ; i < n ; i ++ ) { 
            a [ i ] = in.nextInt ( ) ; // Populate the array with n integers
        } 
        Arrays.sort ( a ) ; // Sort the array
        for ( int i = 0 ; i < a.length - 1 ; i ++ ) { 
            if ( a [ i + 1 ] < a [ i ] * 2 && a [ i ] != a [ i + 1 ] ) { // Check if any element is less than twice the previous element
                System.out.println ( "YES" ) ; 
                return ; // Exit the program after printing "YES"
            } 
        } 
        System.out.println ( "NO" ) ; // Print "NO" if no such condition is found
    } 
}

