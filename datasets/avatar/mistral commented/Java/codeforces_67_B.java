
import java.io.* ;  // Importing required Java packages for input and output streams and utilities
import java.util.* ;

public class Main {
  Main ( ) {             // Constructor for the Main class with System.out as the output stream and set to flush output after each line
    this ( System.out , true ) ;
  }

  Scanner sc = new Scanner ( System.in ) ;  // Creating a Scanner object for reading input from the standard input stream

  public static void main ( String [ ] $ ) {
    Main o = new Main ( ) ;  // Creating an instance of the Main class
    o.main ( ) ;             // Calling the main method of the Main class
    o.flush ( ) ;            // Flushing the output stream to ensure all output is written to the console
  }

  void main ( ) {
    int n = sc.nextInt ( ) ;  // Reading the number of elements in the array 'bb' from the standard input
    int k = sc.nextInt ( ) ;  // Reading the value of 'k' from the standard input
    int [ ] bb = new int [ n ] ;  // Creating an integer array 'bb' of size 'n'

    for ( int i = 0 ; i < n ; i ++ ) {
      bb [ i ] = sc.nextInt ( ) ;  // Reading each element of the array 'bb' from the standard input
    }

    int [ ] aa = new int [ n ] ;  // Creating an integer array 'aa' of size 'n'
    int m = 0 ;                 // Initializing an integer variable 'm' to keep track of the index of the last element added to 'aa'

    for ( int a = n - 1 ; a >= 0 ; a -- ) {  // Iterating through the array 'bb' from the last index to the first index
      int j = 0 ;
      while ( bb [ a ] > 0 ) {  // While there are still elements in 'bb' at index 'a' to be processed
        if ( aa [ j ] >= a + k ) {  // Checking if the current element in 'aa' is greater than or equal to the index 'a' plus 'k'
          bb [ a ] -- ;  // If true, decrement the number of elements in 'bb' at index 'a'
        }
        j ++ ;
      }

      for ( int j_ = m ++ ; j_ > j ; j_ -- ) {  // Iterating through the array 'aa' from the last index added to the current index 'j'
        aa [ j_ ] = aa [ j_ - 1 ] ;  // Swapping the elements at indices 'j_' and 'j_ - 1'
      }

      aa [ j ] = a ;  // Adding the current index 'a' to the array 'aa' at index 'j'
    }

    for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through the array 'aa' and printing each element to the console
      print ( aa [ i ] + 1 + " " ) ;
    }

    println ( ) ;  // Printing a newline character to the console
  }
}

These comments should provide a clear understanding of the logic behind each block of code. Let me know if you need any further clarification or modifications.