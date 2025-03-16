
import java.util.* ;  // Importing necessary utility classes
import java.math.* ;

public class Main {
    static int mod = ( int ) 1e9 + 7 ;  // Defining a constant value for modulo arithmetic

    static int DX [ ] = { - 1 , 0 , 1 , 0 } , DY [ ] = { 0 , - 1 , 0 , 1 } ;  // Defining the four directions for BFS/DFS

    static int n ;  // Number of elements in the array 'a'
    static long k ;  // A given value
    static long a [ ] ;  // The array to be processed

    public static void main ( String [ ] args ) {
        Scanner fs = new Scanner ( System.in ) ;  // Creating a new Scanner object to read input from the standard input

        n = fs.nextInt ( ) ;  // Reading the number of elements in the array 'a'
        k = fs.nextLong ( ) ;  // Reading the given value 'k'
        a = new long [ n ] ;  // Allocating memory for the array 'a'

        for ( int i = 0 ; i < n ; ++ i ) {  // Reading the elements of the array 'a'
            a [ i ] = fs.nextLong ( ) ;
        }

        Arrays.sort ( a ) ;  // Sorting the elements of the array 'a' in ascending order

        long INF = ( long ) ( 1e18 ) + 1 ;  // Defining a large constant value for the upper bound of the binary search range
        long l = - INF ;  // Initializing the lower bound of the binary search range to a very large negative value
        long r = INF ;  // Initializing the upper bound of the binary search range to a very large positive value

        while ( l + 1 < r ) {  // Performing binary search to find the answer
            long c = ( l + r ) / 2 ;
            if ( check ( c ) ) l = c ;  // If the condition is satisfied, update the lower bound
            else r = c ;  // Otherwise, update the upper bound
        }

        System.out.println ( l ) ;  // Printing the answer
    }

    static boolean check ( long x ) {  // A helper function to check if the condition is satisfied
        long tot = 0 ;  // Initializing a variable to store the total number of elements that can be covered

        for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through all the elements in the array 'a'
            long now = a [ i ] ;  // Reading the current element
            int l = 0 , r = n ;  // Initializing the left and right indices for the binary search

            if ( now >= 0 ) {  // If the current element is non-negative
                while ( l < r ) {  // Performing binary search to find the index 'c' such that 'now * a[c]' is close to 'x'
                    int c = ( l + r ) / 2 ;
                    if ( now * a [ c ] < x ) l = c + 1 ;  // If 'now * a[c]' is smaller than 'x', update the left index
                    else r = c ;  // Otherwise, update the right index
                }
                tot += l ;  // Adding the index 'l' to the total number of elements that can be covered
            } else {  // If the current element is negative
                while ( l < r ) {  // Performing binary search to find the index 'c' such that 'now * a[c]' is greater than or equal to 'x'
                    int c = ( l + r ) / 2 ;
                    if ( now * a [ c ] >= x ) l = c + 1 ;  // If 'now * a[c]' is greater than or equal to 'x', update the left index
                    else r = c ;  // Otherwise, update the right index
                }
                tot += ( n - l ) ;  // Adding the remaining elements to the total number of elements that can be covered
            }

            if ( ( long ) a [ i ] * a [ i ] < x ) tot -- ;  // If the square of the current element is smaller than 'x', decrement the total number of elements that can be covered

            if ( tot / 2 < k ) return true ;  // If the total number of elements that can be covered is less than 'k', return true
        }

        return false ;  // Otherwise, return false
    }
}