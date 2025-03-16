
import java.io.* ; // Importing required Java packages for file I/O and streams
import java.util.* ; // Importing required Java package for collections

public class Main {
  // Declaring a private static BufferedReader variable for reading input from the console
  private static BufferedReader br = null ;

  public static void main ( String [ ] args ) {
    int n ; // Declaring an integer variable 'n' to store the number of test cases

    // Reading the first line of input which contains the number of test cases
    n = Integer.parseInt ( read ( 1 ) [ 0 ] ) ;

    // Checking if the number of test cases is equal to 1
    if ( n == 1 ) {
      // If yes, printing "Hello World" as output
      System.out.println ( "Hello World" ) ;
    } else {
      // If not, reading the next two lines of input which contain two integers
      String [ ] strs = read ( 2 ) ;
      int num1 = Integer.parseInt ( strs [ 0 ] ) ; // Storing the first integer in a variable 'num1'
      int num2 = Integer.parseInt ( strs [ 1 ] ) ; // Storing the second integer in a variable 'num2'

      // Printing the sum of the two integers as output
      System.out.println ( num1 + num2 ) ;
    }
  }

  // A method to read input from the console and return it as a String array
  private static String [ ] read ( int len ) {
    List < String > strList = new ArrayList < > ( ) ; // Creating an empty ArrayList to store the input lines

    try {
      if ( br == null ) { // Checking if the BufferedReader variable is null
        br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; // Creating a new BufferedReader object if it's null
      }

      // Reading 'len' number of lines from the console and adding them to the ArrayList
      for ( int i = 0 ; i < len ; i ++ ) {
        strList.add ( br.readLine ( ) ) ;
      }
    } catch ( IOException e ) {
      // Handling any I/O exceptions that might occur during the input reading process
    }

    // Converting the ArrayList to a String array and returning it
    return strList.toArray ( new String [ 0 ] ) ;
  }

  // A method to close the BufferedReader object after the input reading process is complete
  private static void close ( ) {
    try {
      if ( br != null ) { // Checking if the BufferedReader object is not null
        br.close ( ) ; // Closing the BufferedReader object if it's not null
      }
    } catch ( IOException e ) {
      // Handling any I/O exceptions that might occur during the BufferedReader closing process
    }
  }
}