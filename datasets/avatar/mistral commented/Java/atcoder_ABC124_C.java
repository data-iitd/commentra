
import java.io.OutputStream ; // Output stream to write output
import java.io.IOException ; // For handling I/O exceptions
import java.io.InputStream ; // Input stream to read input
import java.util.StringTokenizer ; // For handling string tokenization
import java.io.IOException ; // For handling I/O exceptions
import java.io.BufferedReader ; // For reading input using BufferedReader
import java.io.InputStreamReader ; // For reading input using InputStreamReader
import java.io.InputStream ; // Input stream to read input

public class Main {
  // Main method to start the program
  public static void main ( String [ ] args ) {
    InputStream inputStream = System.in ; // Input stream to read input from standard input
    OutputStream outputStream = System.out ; // Output stream to write output to standard output
    InputReader in = new InputReader ( inputStream ) ; // Initialize InputReader
    PrintWriter out = new PrintWriter ( outputStream ) ; // Initialize PrintWriter

    CColoringColorfully solver = new CColoringColorfully ( ) ; // Initialize solver object
    solver.solve ( 1 , in , out ) ; // Solve the problem and print the output

    out.close ( ) ; // Close the PrintWriter
  }

  // Static inner class to solve the problem
  static class CColoringColorfully {
    public void solve ( int testNumber , InputReader in , PrintWriter out ) {
      String x = in.next ( ) ; // Read the input string
      StringBuilder a = new StringBuilder ( x ) ; // Create a StringBuilder object 'a' with the same string as 'x'
      StringBuilder b = new StringBuilder ( x ) ; // Create a StringBuilder object 'b' with the same string as 'x'
      int a1 = 0 ; // Initialize counter for number of consecutive '1's in string 'a'
      int a2 = 0 ; // Initialize counter for number of consecutive '1's in string 'b'

      // Loop through each character in string 'a' starting from index 1
      for ( int i = 1 ; i < x.length ( ) ; i ++ ) {
        if ( a.charAt ( i ) == a.charAt ( i - 1 ) ) { // Check if current character is same as previous character
          if ( a.charAt ( i ) == '1' ) a.setCharAt ( i , '0' ) ; // If '1', change it to '0'
          else a.setCharAt ( i , '1' ) ; // If not '1', change it to '1'
          a1 ++ ; // Increment counter for number of consecutive '1's
        }
      }

      // Loop through each character in string 'b' starting from the last character
      for ( int i = x.length ( ) - 1 ; i > 0 ; i -- ) {
        if ( b.charAt ( i ) == b.charAt ( i - 1 ) ) { // Check if current character is same as previous character
          if ( b.charAt ( i - 1 ) == '1' ) b.setCharAt ( i - 1 , '0' ) ; // If '1', change it to '0'
          else b.setCharAt ( i - 1 , '1' ) ; // If not '1', change it to '1'
          a2 ++ ; // Increment counter for number of consecutive '1's
        }
      }

      // Print the minimum number of consecutive '1's in strings 'a' and 'b'
      out.println ( Math.min ( a1 , a2 ) ) ;
    }
  }

  // Static inner class to read input
  static class InputReader {
    BufferedReader reader ;
    StringTokenizer tokenizer ;

    public InputReader ( InputStream stream ) {
      reader = new BufferedReader ( new InputStreamReader ( stream ) , 32768 ) ;
      tokenizer = null ;
    }

    public String next ( ) {
      while ( tokenizer == null || ! tokenizer.hasMoreTokens ( ) ) {
        try {
          tokenizer = new StringTokenizer ( reader.readLine ( ) ) ;
        } catch ( IOException e ) {
          throw new RuntimeException ( e ) ;
        }
      }
      return tokenizer.nextToken ( ) ;
    }
  }
}