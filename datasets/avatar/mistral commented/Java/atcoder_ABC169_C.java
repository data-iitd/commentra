
import java.util.ArrayList ;  // Importing ArrayList class
import java.util.LinkedList ; // Importing LinkedList class
import java.util.Scanner ;    // Importing Scanner class

public class Main {

    public static void main ( String [ ] args ) {
        // Initializing Scanner object to read input from the console
        Scanner sc = new Scanner ( System.in ) ;

        long a; // Declaring and initializing long variable 'a'
        a = sc.nextLong ( ) ; // Reading long value from the console and assigning it to 'a'

        String b; // Declaring and initializing String variable 'b'
        b = sc.next ( ) ; // Reading String value from the console and assigning it to 'b'

        char [ ] bChar = b.toCharArray ( ) ; // Converting String 'b' to char array 'bChar'
        int length = bChar.length ; // Getting length of char array 'bChar'

        String bStr = "" ; // Initializing empty String variable 'bStr'
        for ( int i = 0 ; i < length ; i ++ ) {
            // Loop to iterate through each character in char array 'bChar'

            if ( bChar [ i ] != '.' ) {
                // If current character is not '.', add it to String 'bStr'
                bStr += bChar [ i ] ;
            }
        }

        int bInt; // Declaring and initializing integer variable 'bInt'
        bInt = Integer.parseInt ( bStr ) ; // Converting String 'bStr' to integer and assigning it to 'bInt'

        long result; // Declaring and initializing long variable 'result'
        result = ( a * bInt ) / 100 ; // Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to 'result'

        System.out.println ( result ) ; // Printing the value of 'result' to the console