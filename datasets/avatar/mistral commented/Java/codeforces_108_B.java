
import java.util.Arrays ; // Importing the Arrays class for sorting the array
import java.util.Scanner ; // Importing the Scanner class for taking user input

public class Main {
  // Main method is the starting point of the Java application
  public static void main ( String [ ] args ) {
    Scanner in = new Scanner ( System.in ) ; // Creating a new Scanner object to read user input
    int n = in.nextInt ( ) ; // Reading the number of elements in the array from user input
    int a [ ] = new int [ n ] ; // Creating an integer array of size n

    // Initializing the array with user input
    for ( int i = 0 ; i < n ; i ++ ) {
      a [ i ] = in.nextInt ( ) ;
    }

    // Sorting the array in ascending order
    Arrays.sort ( a ) ;

    // Checking if there is any pair of adjacent elements that satisfy the condition
    for ( int i = 0 ; i < a.length - 1 ; i ++ ) {
      // Checking if the next element is less than twice the current element and they are not the same
      if ( a [ i + 1 ] < a [ i ] * 2 && a [ i ] != a [ i + 1 ] ) {
        System.out.println ( "YES" ) ; // Printing "YES" if a pair is found
        return ; // Exiting the method if a pair is found
      }
    }

    // If no pair is found, printing "NO"
    System.out.println ( "NO" ) ;
  }
}