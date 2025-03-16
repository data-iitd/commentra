
import java.io.BufferedReader ; // Importing BufferedReader for input operations
import java.io.InputStreamReader ; // Importing InputStreamReader for input stream
import java.io.IOException ; // Importing IOException for exception handling

public class Main {
    public static void main ( String [ ] args ) throws IOException {
        BufferedReader in = new BufferedReader ( new InputStreamReader ( System.in ) ) ; // Creating a BufferedReader object to read input
        String [ ] str = in.readLine ( ).split ( " " ) ; // Reading input and splitting it by spaces
        int h = Integer.parseInt ( str [ 0 ] ) ; // Parsing the first element to an integer representing the height
        int a = Integer.parseInt ( str [ 1 ] ) ; // Parsing the second element to an integer representing the amount to subtract
        int num = 0 ; // Initializing a counter to keep track of the number of subtractions

        // Implementing a loop to subtract 'a' from 'h' until 'h' is less than or equal to 0
        for ( int i = 1 ; h > 0 ; i ++ ) {
            h = h - a ; // Subtracting 'a' from 'h'
            num ++ ; // Incrementing the counter
        }

        System.out.println ( num ) ; // Printing the result, which is the number of subtractions
    }
}

