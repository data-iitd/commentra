// Importing necessary packages
import java.util.* ;

// Declaring the main class 'Main'
public class Main {

    // Defining the main method
    public static void main ( String [ ] args ) {

        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner ( System.in ) ;

        // Reading the number of strings 'num' from the user input
        int num = sc.nextInt ( ) ;

        // Initializing an ArrayList of strings 'arr' with a size equal to 'num'
        ArrayList < String > arr = new ArrayList < > ( num ) ;

        // Reading each string 's' from the user input and adding it to the ArrayList 'arr'
        for ( int i = 0 ; i < num ; i ++ ) {
            String s = sc.next ( ) ;
            arr.add ( s ) ;
        }

        // Initializing two variables 'counter' and 'fine'
        int counter = 0 ;
        int fine = 0 ;

        // The first nested loop to iterate through each character in each string
        for ( int i = 0 ; i < num ; i ++ ) {
            for ( int k = 0 ; k < num ; k ++ ) {
                // Checking if the character at position (i,k) in the string at index 'i' is 'C'
                if ( arr.get ( i ).charAt ( k ) == 'C' ) {
                    // Incrementing the counter variable
                    counter ++ ;
                }
            }
            // Calculating the fine based on the number of 'C' characters in the current string
            fine += ( counter * ( counter - 1 ) ) / 2 ;
            // Resetting the counter variable for the next string
            counter = 0 ;
        }

        // The second nested loop to iterate through each character in each string again
        for ( int i = 0 ; i < num ; i ++ ) {
            for ( int k = 0 ; k < num ; k ++ ) {
                // Checking if the character at position (i,k) in the string at index 'k' is 'C'
                if ( arr.get ( k ).charAt ( i ) == 'C' ) {
                    // Incrementing the counter variable
                    counter ++ ;
                }
            }
            // Calculating the fine based on the number of 'C' characters in the current string
            fine += ( counter * ( counter - 1 ) ) / 2 ;
            // Resetting the counter variable for the next string
            counter = 0 ;
        }

        // Printing the final result 'fine'
        System.out.println ( fine ) ;

        // Closing the Scanner object
        sc.close ( ) ;

        // Closing the main method
    }

    // Closing the main class 'Main'
}