
import java.util.* ; 
import static java.lang.Math.* ; 

public class Main { 
    public static void main ( String args [ ] ) { 
        Scanner in = new Scanner ( System.in ) ; 
        int x = 0 , y = 0 ; 
        int t = 0 ; 
        int n = in.nextInt ( ) ; // Read the integer n
        String str = in.next ( ) ; // Read the string str
        char l [ ] = new char [ str.length ( ) ] ; 
        l = str.toCharArray ( ) ; // Convert the string to a character array

        // Check each character in the character array
        for ( int i = 0 ; i < n ; i ++ ) { 
            if ( l [ i ] != '4' && l [ i ] != '7' ) { 
                t = 1 ; // Set t to 1 if a character is neither '4' nor '7'
            } 
        } 

        // If t is 1, print "NO"
        if ( t == 1 ) { 
            System.out.println ( "NO" ) ; 
        } else { 
            // Calculate the sum of the first half of the character array
            for ( int i = 0 ; i < n / 2 ; i ++ ) { 
                x = x + Character.getNumericValue ( l [ i ] ) ; 
            } 
            // Calculate the sum of the second half of the character array
            for ( int i = n - 1 ; i > ( n / 2 ) - 1 ; i -- ) { 
                y = y + Character.getNumericValue ( l [ i ] ) ; 
            } 
            // If x equals y, print "YES", otherwise print "NO"
            if ( x == y ) { 
                System.out.println ( "YES" ) ; 
            } else { 
                System.out.println ( "NO" ) ; 
            } 
        } 
    } 
}

