import java.util.Scanner ;  // Importing Scanner class for user input

public class Main {
    public static void main ( String [ ] args ) {  // Main method to start the program
        Scanner ob = new Scanner ( System.in ) ;  // Creating a Scanner object for user input
        int n = ob.nextInt ( ) ;  // Reading the number of elements in the array from user input
        int array [ ] = new int [ n + 1 ] ;  // Creating an array of size n+1 to store the input elements

        // Reading the elements of the array from user input
        for ( int i = 1 ; i <= n ; i ++ ) {
            array [ i ] = ob.nextInt ( ) ;  // Reading the i-th element of the array
        }

        int odd = 0 , even = 0 , odd_ind = 0 , even_ind = 0 ;  // Initializing variables for counting odd and even elements and their indices

        // Counting the number of odd and even elements and storing their indices
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( array [ i ] % 2 == 0 ) {  // If the current element is even
                even ++ ;  // Increment the count of even elements
                even_ind = i ;  // Store the index of the current even element
            } else {  // If the current element is odd
                odd ++ ;  // Increment the count of odd elements
                odd_ind = i ;  // Store the index of the current odd element
            }
        }

        // Determining the output based on the count of odd and even elements
        if ( odd > even ) {  // If there are more odd elements than even elements
            System.out.println ( even_ind ) ;  // Print the index of the last even element
        } else {  // If there are more even elements than odd elements
            System.out.println ( odd_ind ) ;  // Print the index of the last odd element
        }
    }
}
