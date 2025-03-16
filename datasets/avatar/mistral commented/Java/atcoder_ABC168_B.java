
import java.util.Scanner ; // Import the Scanner class for reading input

public class Main { // Define the Main class

    public static void main ( String [ ] args ) { // Define the main method as the entry point of the program

        Scanner in = new Scanner ( System.in ) ; // Create a new Scanner object to read input from the standard input stream

        int K = in.nextInt ( ) ; // Read the first integer `K` from the input

        String S = in.next ( ) ; // Read the next token from the input, which is assumed to be a string `S`

        if ( S.length ( ) <= K ) { // Check if the length of the string `S` is less than or equal to the integer `K`

            System.out.println ( S ) ; // If the condition is true, print the string `S` to the standard output

        } else { // If the condition is false

            System.out.println ( S.substring ( 0 , K ) + "..." ) ; // Print the first `K` characters of the string `S` followed by "..." to the standard output

        }

    }

}