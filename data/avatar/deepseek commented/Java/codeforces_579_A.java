import java.util.* ; // Importing all utilities from java.util package
import java.util.ArrayList ; // Importing ArrayList class (redundant in this case)

public class Main {
    public static void main ( String [ ] args ) {
        Scanner str = new Scanner ( System.in ) ; // Creating a Scanner object to read input
        int n = str.nextInt ( ) ; // Reading an integer input
        String s = "" ; // Initializing an empty string to store binary representation
        
        // Converting the integer to binary representation
        while ( n > 0 ) {
            int x = n % 2 ; // Getting the remainder when divided by 2
            n /= 2 ; // Dividing the number by 2
            s += x + "" ; // Appending the remainder to the string
        }
        
        int ans = 0 ; // Initializing a variable to count the number of '1's
        
        // Counting the number of '1's in the binary representation
        for ( int i = 0 ; i < s.length ( ) ; i ++ ) {
            if ( s.charAt ( i ) == '1' ) {
                ans ++ ; // Incrementing the count if the character is '1'
            }
        }
        
        System.out.println ( ans ) ; // Printing the count of '1's
    }
}
