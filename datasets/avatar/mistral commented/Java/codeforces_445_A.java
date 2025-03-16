
import java.io.* ;

// Main class with a main method as the entry point of the Java application
public class Main {

 // Read input from the standard input stream using a BufferedReader object
  public static void main ( String [ ] args ) throws IOException {
    BufferedReader buf = new BufferedReader ( new InputStreamReader ( System.in ) ) ;

    // Read the first line of input and split it into an array of strings
    String [ ] inp = buf.readLine ( ).split ( "" ) ;

    // Parse the first two elements of the array into integers n and m
    int n = Integer.parseInt ( inp [ 0 ] ) ;
    int m = Integer.parseInt ( inp [ 1 ] ) ;

    // Create an array ans of size n to store the processed strings
    String [ ] ans = new String [ n ] ;

    // Iterate through each string in the input
    for ( int i = 0 ; i < n ; i ++ ) {
      String str = buf.readLine ( ) ; // Read a string from the input
      StringBuilder temp = new StringBuilder ( "" ) ; // Initialize an empty StringBuilder object

      // Iterate through each character in the string
      for ( int j = 0 ; j < m ; j ++ ) {
        if ( str.charAt ( j ) == '-' ) { // If the character is a '-'
          temp.append ( "-" ) ; // Append a '-' character to temp
        } else {
          if ( ( i + j ) % 2 == 1 ) { // If the index i + j is odd
            temp.append ( "W" ) ; // Append 'W' character to temp
          } else {
            temp.append ( "B" ) ; // Otherwise, append 'B' character to temp
          }
        }
      }

      // Store the final string in the ans array using the index i
      ans [ i ] = temp.toString ( ) ;
    }

    // Iterate through each string in the ans array and print it to the standard output stream
    for ( int i = 0 ; i < n ; i ++ ) {
      System.out.println ( ans [ i ] ) ;
    }
  }
}