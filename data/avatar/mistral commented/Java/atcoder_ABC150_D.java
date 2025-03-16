
import java.util.* ; // Importing the utility class Scanner

public class Main { // Defining the class Main

    public static void main ( String [ ] args ) { // Starting the main method
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input
        int n = Integer.parseInt ( sc.next ( ) ) ; // Reading the first integer n from the standard input
        int m = Integer.parseInt ( sc.next ( ) ) ; // Reading the second integer m from the standard input
        int [ ] a = new int [ n ] ; // Creating an integer array a of size n

        // Initializing the array a with input values
        for ( int i = 0 ; i < n ; i ++ ) {
            a [ i ] = Integer.parseInt ( sc.next ( ) ) / 2 ; // Reading an integer value and dividing it by 2 before storing it in the array
        }

        long gcd ; // Declaring a variable gcd to store the greatest common divisor
        long lcd = 1 ; // Declaring and initializing a variable lcm to store the least common multiple

        // Finding the least common multiple of all array elements
        for ( int i = 0 ; i < n ; i ++ ) {
            gcd = getGCD ( lcd , a [ i ] ) ; // Finding the greatest common divisor of lcm and the current array element
            lcd = lcd * a [ i ] / gcd ; // Updating the value of lcm

            // Checking if lcm is greater than m
            if ( lcd > m ) {
                System.out.println ( 0 ) ; // If true, printing 0 and returning from the method
                return ;
            }
        }

        // Checking if any array element is a factor of lcm
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( ( lcd / a [ i ] ) % 2 == 0 ) { // Checking if the remainder of lcm divided by the current array element is 0 and even
                System.out.println ( 0 ) ; // If true, printing 0 and returning from the method
                return ;
            }
        }

        // Printing the result
        System.out.println ( ( m / lcd + 1 ) / 2 ) ;
    }

    // A helper method to find the greatest common divisor of two numbers
    public static long getGCD ( long a , long b ) {
        if ( b == 0 ) { // Base case: if b is 0, return a as the gcd
            return a ;
        } else {
            return getGCD ( b , a % b ) ; // Recursive call: finding the gcd of b and the remainder of a divided by b
        }
    }
}