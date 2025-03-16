
import java.util.* ; // Importing the utility class Scanner
import java.lang.* ; // Importing the basic Java classes

public class Main {
    public static void main ( String [ ] args ) {
        Scanner scan = new Scanner ( System.in ) ; // Creating a new Scanner object named scan to read input from the standard input

        long N = scan.nextLong ( ) ; // Reading the first long integer `N` from the standard input
        long A = scan.nextLong ( ) ; // Reading the second long integer `A` from the standard input
        long B = scan.nextLong ( ) ; // Reading the third long integer `B` from the standard input

        long k = 0 ; // Initializing a long variable `k` with the value 0

        if ( isValidInput ( N , A , B ) ) { // Checking if the input values are valid
            if ( A + B <= N ) { // Checking if the sum of `A` and `B` is less than or equal to `N`
                k = calculateK ( N , A , B ) ; // Calculating the number of times `A + B` can be added to `N` and storing the result in `k`

                if ( remainingPartGreaterThanA ( N , k , A ) ) { // Checking if the remaining part of `N` after subtracting `k * (A + B)` is greater than `A`
                    printResult ( N , k , A ) ; // Printing the result of the expression `A * k + (N - k * (A + B)) - (N - (k * (A + B) + A))`
                } else {
                    printResult ( N , k , A ) ; // Printing the result of the expression `A * k + (N - k * (A + B))`
                }
            } else if ( A + B > N && A <= N ) { // Checking if the sum of `A` and `B` is greater than `N`, but `A` is less than or equal to `N`
                printA ( ) ; // Printing the value of `A`
            } else { // If neither of the above conditions is true
                printN ( ) ; // Printing the value of `N`
            }
        }

        scan.close ( ) ; // Closing the Scanner object to save system resources
    }

    private static boolean isValidInput ( long n , long a , long b ) {
        return ( 1 <= n && n <= Math.pow ( 10 , 18 ) && 0 <= a && 0 <= b && 0 < a + b && a + b <= Math.pow ( 10 , 18 ) ) ;
    }

    private static long calculateK ( long n , long a , long b ) {
        return n / ( a + b ) ;
    }

    private static boolean remainingPartGreaterThanA ( long n , long k , long a ) {
        return ( n - k * ( a + b ) ) > a ;
    }

    private static void printResult ( long n , long k , long a ) {
        long result = 0 ;
        if ( remainingPartGreaterThanA ( n , k , a ) ) {
            result = a * k + ( n - k * ( a + b ) ) - ( n - ( k * ( a + b ) + a ) ) ;
        } else {
            result = a * k + ( n - k * ( a + b ) ) ;
        }
        System.out.println ( result ) ;
    }

    private static void printA ( ) {
        System.out.println ( A ) ;
    }

    private static void printN ( ) {
        System.out.println ( N ) ;
    }
}