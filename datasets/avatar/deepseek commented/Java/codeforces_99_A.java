
import java.util.Scanner ; 
import java.util.ArrayList ; 
import java.util.Arrays ; 
import java.math.BigInteger ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Read input string from the user
        char [ ] str = new Scanner ( System.in ).nextLine ( ).toCharArray ( ) ; 

        // Find the index of the dot ('.') in the string
        int dotIndex = 0 ; 
        for ( int i = 0 ; i < str.length ; i ++ ) 
            if ( str [ i ] == '.' ) { 
                dotIndex = i ; 
                break ; 
            } 

        // Check if the character before the dot is '9'
        if ( str [ dotIndex - 1 ] == '9' ) { 
            System.out.println ( "GOTO Vasilisa." ) ; 
        } 
        // If the character before the dot is not '9', check the digit after the dot
        else if ( Integer.parseInt ( str [ dotIndex + 1 ] + "" ) > 4 ) { 
            // Increment the number before the dot by 1 and print the result
            String _str = "" ; 
            for ( int i = 0 ; i < dotIndex ; i ++ ) 
                _str += str [ i ] ; 
            System.out.println ( new BigInteger ( _str ).add ( new BigInteger ( "1" ) ).toString ( ) ) ; 
        } 
        // If the digit after the dot is 4 or less, print the number before the dot without any changes
        else { 
            for ( int i = 0 ; i < dotIndex ; i ++ ) 
                System.out.print ( str [ i ] ) ; 
            System.out.println ( ) ; 
        } 
    } 
}
