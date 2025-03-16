
import java.util.Scanner ;

public class Main {
    public static void main ( String [ ] args ) {
        // Initialize a Scanner object to read input from the standard input stream
        Scanner in = new Scanner ( System.in ) ;

        // Read the first integer `T` from the input
        int T = in.nextInt ( ) ;

        // Read the second integer `S` from the input
        int S = in.nextInt ( ) ;

        // Read the third integer `q` from the input
        int q = in.nextInt ( ) ;

        // Initialize the variable `previous` with the value of `S`
        long previous = S ;

        // Initialize the variable `answer` with the value of 0
        int answer = 0 ;

        // Start a while loop that continues as long as `previous` is less than `T`
        while ( previous < T ) {
            // Increment the value of `answer` by 1
            answer ++ ;

            // Multiply the value of `previous` by `q`
            previous *= q ;
        }

        // Print the value of `answer` to the standard output stream
        System.out.println ( answer ) ;
    }
}