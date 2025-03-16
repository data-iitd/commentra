
import java.io.* ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; // Initialize Scanner to read input
        int n = sc.nextInt ( ) ; // Read the first integer input
        int m = sc.nextInt ( ) ; // Read the second integer input

        // Check if n is 0
        if ( n == 0 ) { 
            if ( m != 0 ) // If n is 0 but m is not 0, print "Impossible"
                System.out.println ( "Impossible" ) ; 
            else // If both n and m are 0, print "0 0"
                System.out.println ( 0 + " " + 0 ) ; 
            return ; // Exit the program
        } 

        // If n is not 0, check if m is less than or equal to n
        if ( m <= n ) { 
            if ( m == 0 ) { // If m is 0, set m to 1
                m = 1 ; 
            } 
            System.out.print ( n + " " + ( m + n - 1 ) ) ; // Print the values of n and m + n - 1
            return ; // Exit the program
        } 

        // If m is greater than n, print the values of m and m + n - 1
        System.out.print ( m + " " + ( m + n - 1 ) ) ; 
    } 
}

