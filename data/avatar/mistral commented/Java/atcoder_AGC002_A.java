// Import the Scanner class from the java.util package
import java.util.Scanner ;

// Define the main method as the entry point of the program
public static void main ( String [ ] args ) {
  // Create a new Scanner object to read input from the standard input stream
  Scanner scanner = new Scanner ( System.in ) ;

  // Read the first integer input from the user
  int a = scanner.nextInt ( ) ;

  // Read the second integer input from the user
  int b = scanner.nextInt ( ) ;

  // Check if the first integer 'a' is positive
  if ( a > 0 ) {
    // If 'a' is positive, print the message "Positive" to the standard output stream
    System.out.println ( "Positive" ) ;
  }

  // Else if the second integer 'b' is non-negative
  else if ( b >= 0 ) {
    // If 'b' is non-negative, print the message "Zero" to the standard output stream
    System.out.println ( "Zero" ) ;
  }

  // Else if the difference between 'b' and 'a' is even
  else if ( ( b - a + 1 ) % 2 == 0 ) {
    // If the difference is even, print the message "Positive" to the standard output stream
    System.out.println ( "Positive" ) ;
  }

  // Else, print the message "Negative" to the standard output stream
  else {
    System.out.println ( "Negative" ) ;
  }
}
