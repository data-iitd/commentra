import java.util.Scanner ; // Importing the Scanner class for reading input

public class Main { // Defining the main class
    public static void main ( String [ ] args ) { // Starting the main method
        Scanner in = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the console
        
        char [ ] n = in.next ( ).toCharArray ( ) ; // Reading a string from the console and converting it to a character array

        boolean s = false ; // Initializing a boolean variable 's' to false

        for ( int i = 0 ; i < n.length ; i ++ ) { // Starting a for loop to iterate through each character in the character array 'n'
            if ( n [ i ] == '.' ) { // Checking if the current character is a '.'
                if ( s ) { // If the boolean variable 's' is true
                    System.out.print ( 1 ) ; // Printing '1' to the console
                    s = false ; // Setting the boolean variable 's' to false
                } else { // If the boolean variable 's' is false
                    System.out.print ( 0 ) ; // Printing '0' to the console
                }
            } else { // If the current character is not a '.'
                if ( s ) { // If the boolean variable 's' is true
                    System.out.print ( 2 ) ; // Printing '2' to the console
                    s = false ; // Setting the boolean variable 's' to false
                } else { // If the boolean variable 's' is false
                    s = true ; // Setting the boolean variable 's' to true
                }
            }
        }

        in.close ( ) ; // Closing the Scanner object to free up system resources
    }
}