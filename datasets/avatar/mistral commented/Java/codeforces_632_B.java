
import java.util.* ; // Importing the utility class Scanner from the Java standard library

public class Main { // Defining the Main class

    public static void main ( String [ ] args ) { // Starting point of the program
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input from the standard input stream
        int n = sc.nextInt ( ) ; // Reading the number of elements in the array from the standard input
        int [ ] a = new int [ n ] ; // Creating an integer array of size n

        for ( int i = 0 ; i < n ; i ++ ) { // Iterating through the array to read its elements from the standard input
            a [ i ] = sc.nextInt ( ) ;
        }

        String s = sc.next ( ) ; // Reading the string from the standard input
        long sum = 0 ; // Initializing the sum variable to zero

        for ( int i = 0 ; i < s.length ( ) ; i ++ ) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'B' characters
            char ch = s.charAt ( i ) ;
            if ( ch == 'B' ) sum += a [ i ] ;
        }

        long ans = sum ; // Initializing the answer variable with the sum calculated above
        long sum1 = sum ; // Initializing a temporary sum variable with the sum calculated above

        for ( int i = 0 ; i < s.length ( ) ; i ++ ) { // Iterating through the string to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
            if ( s.charAt ( i ) == 'A' ) sum1 += a [ i ] ;
            else sum1 -= a [ i ] ;
            ans = Math.max ( ans , sum1 ) ;
        }

        sum1 = sum ; // Resetting the temporary sum variable with the sum calculated at the beginning

        for ( int i = s.length ( ) - 1 ; i >= 0 ; i -- ) { // Iterating through the string in reverse order to calculate the sum of the array elements corresponding to the 'A' characters and subtracting the sum of the array elements corresponding to the 'B' characters to find the maximum sum
            if ( s.charAt ( i ) == 'A' ) sum1 += a [ i ] ;
            else sum1 -= a [ i ] ;
            ans = Math.max ( ans , sum1 ) ;
        }

        System.out.println ( ans ) ; // Printing the maximum sum found
    }
}