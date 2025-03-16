import java.util.Scanner ;

public class Main {
    // Entry point of the program
    public static void main ( String [ ] args ) {
        Scanner scan = new Scanner ( System.in ) ; // Initialize a Scanner object to read input from the standard input stream
        int n = scan.nextInt ( ) ; // Read the first integer 'n' from the input
        int count = scan.nextInt ( ) ; // Read the second integer 'count' from the input
        printIsland ( n , count ) ; // Call the printIsland method with the arguments 'n' and 'count'
    }

    // Method to check if it's possible to place the required number of 'L' islands in the grid
    public static void printIsland ( int n , int count ) {
        int a = ( n + 1 ) / 2 ; // Calculate the side length 'a' of the square grid of size 'n x n'
        int b = n / 2 ; // Calculate the square of the side length 'b' of the grid
        int max = a * a + b * b ; // Calculate the maximum number of 'L' islands that can be placed in the grid

        // Check if the count is greater than the maximum number of 'L' islands that can be placed in the grid
        if ( count > max ) {
            System.out.println ( "NO" ) ; // If yes, print "NO" and return from the method
            return ;
        }

        System.out.println ( "YES" ) ; // If not, print "YES" to indicate that it's possible to place the required number of 'L' islands in the grid

        // Initialize a StringBuilder object 'sb' to store a row of the grid
        for ( int i = 0 ; i < n ; i ++ ) {
            StringBuilder sb = new StringBuilder ( ) ;
            for ( int j = 0 ; j < n ; j ++ ) {
                // If the cell is in the position where an 'L' island can be placed, append an 'L' character to the StringBuilder object and decrement the count
                if ( ( i + j ) % 2 == 0 && count > 0 ) {
                    sb.append ( 'L' ) ;
                    count -- ;
                } else {
                    // Otherwise, append an 'S' character to the StringBuilder object
                    sb.append ( 'S' ) ;
                }
            }
            // Print the contents of the StringBuilder object to represent a row of the grid
            System.out.println ( sb ) ;
        }
    }
}
