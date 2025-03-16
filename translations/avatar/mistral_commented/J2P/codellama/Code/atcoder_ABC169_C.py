
import java.util.ArrayList ;  # Importing ArrayList class
import java.util.LinkedList ; # Importing LinkedList class
import java.util.Scanner ;    # Importing Scanner class

public class Main {

    public static void main ( String [ ] args ) {
        # Initializing Scanner object to read input from the console
        sc = Scanner ( System.in ) ;

        a = sc.nextLong ( ) ; # Reading long value from the console and assigning it to 'a'

        b = sc.next ( ) ; # Reading String value from the console and assigning it to 'b'

        bChar = b.toCharArray ( ) ; # Converting String 'b' to char array 'bChar'
        length = bChar.length ; # Getting length of char array 'bChar'

        bStr = "" ; # Initializing empty String variable 'bStr'
        for i in range ( length ):
            # Loop to iterate through each character in char array 'bChar'

            if bChar [ i ] != '.':
                # If current character is not '.', add it to String 'bStr'
                bStr += bChar [ i ] ;

        bInt = int ( bStr ) ; # Converting String 'bStr' to integer and assigning it to 'bInt'

        result = ( a * bInt ) / 100 ; # Multiplying 'a' with 'bInt', then dividing the result by 100 and assigning it to 'result'

        print ( result ) ; # Printing the value of 'result' to the console

