
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner stdIn = new Scanner ( System.in ) ; 
        int N = stdIn.nextInt ( ) ; // Read the integer N from standard input
        int count = 0 ; // Initialize a counter to count the number of digits in N
        int temp = N ; // Initialize a temporary variable to hold the value of N
        int ans = 0 ; // Initialize a variable to accumulate the result

        // Calculate the number of digits in N
        while ( temp > 0 ) { 
            temp /= 10 ; 
            count ++ ; 
        } 

        // Iterate from 1 to the number of digits in N
        for ( int i = 1 ; i <= count ; i ++ ) { 
            if ( i == count ) { // Check if it's the last digit
                if ( i % 2 == 1 ) { // Check if the position is odd
                    ans += ( N - Math.pow ( 10 , i - 1 ) + 1 ) ; // Add the count of numbers with odd positions
                } 
            } else { 
                if ( i == 1 ) { // Check if it's the first digit
                    ans += 9 ; // Add the count of single-digit numbers
                } else if ( i % 2 == 1 ) { // Check if the position is odd
                    ans += ( Math.pow ( 10 , i ) - Math.pow ( 10 , i - 1 ) ) ; // Add the count of numbers in odd positions
                } 
            } 
        } 

        System.out.println ( ans ) ; // Print the result
    } 
}
