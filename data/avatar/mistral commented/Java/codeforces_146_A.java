
import java.util.* ;  // Importing the utility class Scanner and static methods from Math package

public class Main {
 
    public static void main ( String args [ ] ) {
        Scanner in = new Scanner ( System.in ) ;  // Creating a new Scanner object to read input from the standard input
        
        int x = 0 , y = 0 ;  // Declaring and initializing two integer variables x and y
        int t = 0 ;  // Declaring and initializing an integer variable t
        int n = 0 ;  // Declaring and initializing an integer variable n to store the length of the input string
        
        String str = "" ;  // Declaring and initializing an empty String variable str to store the input string
        char l [ ] = null ;  // Declaring and initializing a char array l of size equal to the length of the input string
        
        in.nextInt ( ) ;  // Reading the integer value of n from the standard input
        str = in.next ( ) ;  // Reading the string value of the input from the standard input
        
        l = new char [ str.length ( ) ] ;  // Creating a char array l of size equal to the length of the input string and assigning it the value of the input string using toCharArray() method
        
        for ( int i = 0 ; i < n ; i ++ ) {  // Iterating through each character in the input string
            if ( l [ i ] != '4' && l [ i ] != '7' ) {  // Checking if the current character is not equal to '4' or '7'
                t = 1 ;  // Setting the value of t to 1 if the condition is true
            }
        }
        
        if ( t == 1 ) {  // Checking if the value of t is equal to 1
            System.out.println ( "NO" ) ;  // Printing "NO" if the condition is true
        } else {  // Else part of the if statement
            int sumX = 0 ;  // Declaring and initializing an integer variable sumX to store the sum of the digits in the first half of the string
            int sumY = 0 ;  // Declaring and initializing an integer variable sumY to store the sum of the digits in the second half of the string
            
            for ( int i = 0 ; i < n / 2 ; i ++ ) {  // Iterating through the first half of the string to calculate the sum of its digits
                x = x + Character.getNumericValue ( l [ i ] ) ;  // Adding the value of the current digit to the variable x
            }
            
            for ( int i = n - 1 ; i > ( n / 2 ) - 1 ; i -- ) {  // Iterating through the second half of the string to calculate the sum of its digits
                y = y + Character.getNumericValue ( l [ i ] ) ;  // Adding the value of the current digit to the variable y
            }
            
            if ( x == y ) {  // Checking if the sum of digits in the first half is equal to the sum of digits in the second half
                System.out.println ( "YES" ) ;  // Printing "YES" if the condition is true
            } else {  // Else part of the if statement
                System.out.println ( "NO" ) ;  // Printing "NO" if the condition is false
            }
        }
    }
}

These comments should provide a clear understanding of the logic of the code. Let me know if you need any further assistance.