
import java.io.* ;
import java.util.* ;

public class Main {
    public static void main ( String [ ] args ) {
        // Define a constant for infinity
        final long INF = ( long ) 1e15 ;
        
        // Create a Scanner object to read input
        Scanner sc = new Scanner ( System.in ) ;
        
        // Read the input number as a string
        String number = sc.next ( ) ;
        
        // Create an array to store the digits of the number
        int [ ] digits = new int [ number.length ( ) + 1 ] ;
        
        // Convert the number into an array of digits
        for ( int i = 0 ; i < number.length ( ) ; i ++ ) {
            digits [ i ] = number.charAt ( number.length ( ) - 1 - i ) - '0' ;
        }
        
        // Initialize the total bill to 0
        int bills = 0 ;
        
        // Loop through each digit to calculate the total bill
        for ( int i = 0 ; i <= number.length ( ) ; i ++ ) {
            // Handle the case where the digit is 10
            if ( digits [ i ] == 10 ) {
                digits [ i + 1 ] ++ ;
                digits [ i ] = 0 ;
            }
            
            // Add the digit to the bill if it is less than 5
            if ( digits [ i ] < 5 ) {
                bills += digits [ i ] ;
            }
            // Handle the case where the digit is 5
            else if ( digits [ i ] == 5 ) {
                if ( digits [ i + 1 ] >= 5 ) {
                    digits [ i + 1 ] ++ ;
                }
                bills += 5 ;
            }
            // Handle the case where the digit is greater than 5
            else {
                digits [ i + 1 ] ++ ;
                bills += 10 - digits [ i ] ;
            }
        }
        
        // Print the total bill
        System.out.println ( bills ) ;
    }
}

