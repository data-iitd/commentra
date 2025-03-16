import java.util.Scanner ; // Importing Scanner class for user input
import javax.swing.JOptionPane ; // Importing JOptionPane for displaying messages

public class Main {

    public static void main ( String [ ] args ) {
        Scanner s = new Scanner ( System.in ) ; // Creating a Scanner object for user input

        // Asking user for the size of the array and initializing it
        int a = s.nextInt ( ) ;
        int ar [ ] = new int [ a ] ;

        // Initializing variables for storing maximum and minimum differences
        int max = 0 , min = 0 ;

        // Reading array elements from user input
        for ( int i = 0 ; i < ar.length ; i ++ ) {
            ar [ i ] = s.nextInt ( ) ; // Reading an integer value from user input and storing it in the array
        }

        // Finding maximum and minimum differences between consecutive elements in the array
        for ( int i = 0 ; i < ar.length ; i ++ ) {
            // Finding maximum difference between current element and first element
            max = Math.max ( ar [ i ] - ar [ 0 ] , ar [ ar.length - 1 ] - ar [ i ] ) ;

            // Finding minimum difference between current element and previous element
            if ( i == 0 ) {
                min = ar [ i + 1 ] - ar [ i ] ; // For the first element, minimum difference is between current and next element
            } else if ( i == ar.length - 1 ) {
                min = ar [ i ] - ar [ i - 1 ] ; // For the last element, minimum difference is between current and previous element
            } else {
                min = Math.min ( ar [ i ] - ar [ i - 1 ] , ar [ i + 1 ] - ar [ i ] ) ; // For other elements, minimum difference is between current and previous or next element, whichever is smaller
            }

            // Printing minimum and maximum differences for each pair of consecutive elements
            System.out.println ( min + " " + max ) ;
        }
    }
}