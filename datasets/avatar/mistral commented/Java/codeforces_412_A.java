import java.util.Scanner ;  // Importing the Scanner class for user input

public class Main {
    public static void main ( String [ ] args ) {  // Main method to start the program
        Scanner sc = new Scanner ( System.in ) ;  // Creating a new Scanner object to read user input
        int n = sc.nextInt ( ) ;              // Reading the first integer input from the user
        int k = sc.nextInt ( ) ;              // Reading the second integer input from the user
        String a = sc.next ( ) ;               // Reading the string input from the user

        if ( k > n / 2 ) {                     // Check if k is greater than n/2
            while ( k < n ) {                 // If true, print "RIGHT" until k equals n
                System.out.println ( "RIGHT" ) ;
                k ++ ;
            }
        } else {                              // Else if k is less than n/2
            while ( k > 1 ) {                  // Print "LEFT" until k equals 1
                System.out.println ( "LEFT" ) ;
                k -- ;
            }
        }

        if ( k == 1 ) {                       // If k equals 1
            for ( int i = 0 ; i < a.length ( ) ; i ++ ) { // Iterate through each character in the string
                System.out.println ( "PRINT " + a.charAt ( i ) ) ; // Print the character
                if ( ( i + 1 ) < a.length ( ) ) { // If the index is not the last one
                    System.out.println ( "RIGHT" ) ; // Print "RIGHT"
                }
            }
        } else {                              // Else if k is not equal to 1
            for ( int i = a.length ( ) - 1 ; i >= 0 ; i -- ) { // Iterate through each character in reverse order
                System.out.println ( "PRINT " + a.charAt ( i ) ) ; // Print the character
                if ( ( i - 1 ) >= 0 ) { // If the index is not the first one
                    System.out.println ( "LEFT" ) ; // Print "LEFT"
                }
            }
        }
    }
}
