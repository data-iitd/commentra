
import java.util.* ; // Importing the utility class Scanner

public class Main {
    public static void main ( String [ ] args ) { // Main method to start the program
        Scanner in = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the console
        while ( in.hasNext ( ) ) { // Reading input until the end of the file is reached
            int n = in.nextInt ( ) ; // Reading the number of elements in the arrays
            int [ ] a = new int [ n ] ; // Creating an integer array 'a' of size 'n'
            int [ ] b = new int [ n ] ; // Creating an integer array 'b' of size 'n'
            int s = - 1 ; // Initializing the variable 's' to -1
            for ( int i = 0 ; i < n ; i ++ ) { // Loop to read and initialize the arrays 'a' and 'b'
                a [ i ] = in.nextInt ( ) ; // Reading an integer value and storing it in the 'i'th position of array 'a'
                b [ i ] = 0 ; // Initializing all elements of array 'b' to zero
            }
            int tem = 1 ; // Initializing the variable 'tem' to 1
            int q = 0 ; // Initializing the variable 'q' to 0
            while ( q != n ) { // Main loop to find the sequence length
                s ++ ; // Incrementing the variable 's'
                if ( tem == 1 ) { // If 'tem' is 1, perform the first half of the loop
                    for ( int i = 0 ; i < n ; i ++ ) {
                        if ( a [ i ] <= q && b [ i ] == 0 ) { // Check if the current element in array 'a' is less than or equal to 'q' and its corresponding element in array 'b' is 0
                            b [ i ] = 1 ; // If so, set the corresponding element in array 'b' to 1 and increment 'q'
                        }
                    }
                    tem = 0 ; // Switching the value of 'tem' to 0
                } else { // If 'tem' is 0, perform the second half of the loop
                    for ( int i = n - 1 ; i >= 0 ; i -- ) {
                        if ( a [ i ] <= q && b [ i ] == 0 ) { // Check if the current element in array 'a' is less than or equal to 'q' and its corresponding element in array 'b' is 0
                            b [ i ] = 1 ; // If so, set the corresponding element in array 'b' to 1 and increment 'q'
                        }
                    }
                    tem = 1 ; // Switching the value of 'tem' to 1
                }
            }
            System.out.println ( s ) ; // Printing the length of the sequence found
        }
    }
}