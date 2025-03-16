
import java.util.* ; // Importing the utility class Scanner

public class Main {
    // Main method is the entry point of the Java application
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream

        int x [ ] = new int [ 3 ] ; // Declaring and initializing an integer array x of size 3
        int max = 0 ; // Initializing max to 0

        // Reading the size of the array x from the standard input stream
        for ( int i = 0 ; i < 3 ; ++ i ) {
            x [ i ] = sc.nextInt ( ) ; // Reading the i-th element of the array x from the standard input stream
            max = Math.max ( max , x [ i ] ) ; // Finding the maximum element of the array x
        }

        int k = sc.nextInt ( ) ; // Reading the integer k from the standard input stream

        List < Long > a [ ] = new List [ 3 ] ; // Declaring and initializing an array a of size 3, where each element is a List of Longs

        // Reading the elements of each sub-list a[i] of size x[i] from the standard input stream and sorting it in ascending order
        for ( int i = 0 ; i < 3 ; ++ i ) {
            a [ i ] = new ArrayList < Long > ( ) ;
            for ( int j = 0 ; j < x [ i ] ; ++ j ) {
                a [ i ].add ( sc.nextLong ( ) ) ;
            }
            Collections.sort ( a [ i ] ) ;
        }

        sc.close ( ) ; // Closing the Scanner object

        List < Long > ans = new ArrayList < Long > ( ) ; // Declaring and initializing an empty list ans to store the sum of three elements from different sub-lists that are less than or equal to k

        // Finding all such sums and adding them to the list ans
        for ( int i = 0 ; i < x [ 0 ] ; ++ i ) {
            for ( int j = 0 ; j < x [ 1 ] ; ++ j ) {
                for ( int m = 0 ; m < x [ 2 ] ; ++ m ) {
                    if ( ( i + 1 ) * ( j + 1 ) * ( m + 1 ) <= k ) { // Checking if the product of (i+1), (j+1), and (m+1) is less than or equal to k
                        long tmp = a [ 0 ].get ( x [ 0 ] - i - 1 ) // Getting the (x[0]-i)-th element of the sub-list a[0]
                                + a [ 1 ].get ( x [ 1 ] - j - 1 ) // Getting the (x[1]-j)-th element of the sub-list a[1]
                                + a [ 2 ].get ( x [ 2 ] - m - 1 ) ; // Getting the (x[2]-m)-th element of the sub-list a[2]
                        ans.add ( tmp ) ; // Adding the sum of the three elements to the list ans
                    }
                }
            }
        }

        Collections.sort ( ans ) ; // Sorting the list ans in ascending order

        int n = ans.size ( ) ; // Getting the size of the list ans

        // Printing the i-th element of the list ans, where i is the index of the element to be printed, starting from the last one
        for ( int i = 0 ; i < k ; ++ i ) {
            System.out.println ( ans.get ( n - i - 1 ) ) ;
        }
    }
}