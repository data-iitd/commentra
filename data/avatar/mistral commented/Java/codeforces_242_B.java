
import java.util.ArrayList ;  // Importing ArrayList and Scanner classes
import java.util.Scanner ;
import java.lang.Math ;

public class Main {
    static final int INF = ( int ) 1e9 + 5 ;  // Initializing a large constant value

    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;  // Creating a Scanner object to read input
        int n ;

        // Reading the number of elements in the arrays
        n = sc.nextInt ( ) ;

        ArrayList < Integer > a = new ArrayList < > ( ) ;  // Creating an ArrayList to store the first array elements
        ArrayList < Integer > b = new ArrayList < > ( ) ;  // Creating an ArrayList to store the second array elements

        int left = INF , right = 0 ;  // Initializing left and right variables to store the minimum and maximum elements respectively

        // Reading the elements of the arrays and updating the minimum and maximum elements
        for ( int i = 0 ; i < n ; i ++ ) {
            a.add ( sc.nextInt ( ) ) ;  // Reading an element from the first array and adding it to the ArrayList
            b.add ( sc.nextInt ( ) ) ;  // Reading an element from the second array and adding it to the ArrayList
            left = Math.min ( left , a.get ( i ) ) ;  // Finding the minimum element in the first array
            right = Math.max ( right , b.get ( i ) ) ;  // Finding the maximum element in the second array
        }

        // Checking if there is an element that has the same minimum and maximum value in both arrays
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( left == a.get ( i ) && right == b.get ( i ) ) {  // Checking if the current element in both arrays has the same minimum and maximum value
                System.out.println ( ++ i ) ;  // If true, printing the index of the element
                return ;  // Exiting the program after finding the element
            }
        }

        // If no such element is found, printing -1
        System.out.println ( - 1 ) ;
    }
}