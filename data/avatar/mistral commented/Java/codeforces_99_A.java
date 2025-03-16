
import java.util.Scanner ; // Importing Scanner class for reading input from the console
import java.util.ArrayList ; // Importing ArrayList class for dynamic array
import java.util.Arrays ; // Importing Arrays class for array manipulation
import java.math.BigInteger ; // Importing BigInteger class for big integer arithmetic

public class Main {

 // Main method is the entry point of the Java application
  public static void main ( String [ ] args ) {
    char [ ] str = new char [ str.length + 1 ] ; // Creating a character array of size str.length + 1 to read the entire line from the console
    Scanner scanner = new Scanner ( System.in ) ; // Creating a Scanner object to read input from the console

    // Reading a line of input from the console and storing it in the character array str
    str = scanner.nextLine ( ).toCharArray ( ) ;

    int dotIndex = 0 ; // Initializing dotIndex variable to 0

    // Finding the index of the last occurrence of '.' character in the string
    for ( int i = 0 ; i < str.length ; i ++ )
      if ( str [ i ] == '.' ) {
        dotIndex = i ;
        break ;
      }

    // Checking if the character before the '.' character is '9'
    if ( str [ dotIndex - 1 ] == '9' ) {
      System.out.println ( "GOTO Vasilisa." ) ; // Printing the message if the condition is true
    }

    // Checking if the character after the '.' character is a digit greater than 4
    else if ( Integer.parseInt ( str [ dotIndex + 1 ] + "" ) > 4 ) {
      String _str = "" ; // Initializing an empty string variable _str

      // Creating a substring of the character array str from the beginning to the index of '.' character
      for ( int i = 0 ; i < dotIndex ; i ++ )
        _str += str [ i ] ;

      // Performing big integer addition and printing the result
      System.out.println ( new BigInteger ( _str ).add ( new BigInteger ( "1" ) ).toString ( ) ) ;
    }

    // Printing the substring of the character array str from the beginning to the index of '.' character
    else {
      for ( int i = 0 ; i < dotIndex ; i ++ )
        System.out.print ( str [ i ] ) ;

      // Printing a newline character at the end of the substring
      System.out.println ( ) ;
    }

    scanner.close ( ) ; // Closing the Scanner object to save system resources
  }
}

These comments should provide a clear understanding of the logic behind each block of code. Let me know if you need any further clarification or modification.