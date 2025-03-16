
import java.util.Scanner ; // Import the Scanner class for reading input

public class Main {
  // Define the main method, which is the entry point of the Java application
  public static void main ( String [ ] args ) {
    Scanner sc = new Scanner ( System.in ) ; // Create a new Scanner object to read input from the standard input stream
    int n ; // Declare an integer variable `n` to store the size of the character array
    int i , j ; // Declare two integer variables `i` and `j` to use as loop counters
    char [ ] c ; // Declare a character array `c` of size `n`
    char p = 'a' ; // Declare a character variable `p` to store the current character to be added to the array

    n = sc.nextInt ( ) ; // Read an integer `n` from the standard input using the nextInt method of the Scanner class
    c = new char [ n ] ; // Create a new character array `c` of size `n`

    for ( i = 0 ; i < 4 ; i ++ ) { // Use a for loop to iterate through the first four elements of the array
      for ( j = i ; j < n ; j += 4 ) { // Use a nested for loop to populate every fourth element of the array with the next character
        c [ j ] = ( char ) p ; // Set the current element of the array to the current character
        p ++ ; // Increment the character to be added to the next element
      }
    }

    for ( i = 0 ; i < n ; i ++ ) { // Use a for loop to print each character in the array to the standard output
      System.out.print ( c [ i ] ) ;
    }

    sc.close ( ) ; // Close the Scanner object to release system resources
  }
}