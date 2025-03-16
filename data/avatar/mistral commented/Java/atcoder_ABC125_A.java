import java.util.Scanner ;

public class Main {

    public static void main ( String [ ] args ) {
        // Create a new Scanner object to read input from the standard input stream
        Scanner sc = new Scanner ( System.in ) ;

        // Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
        int sec = sc.nextInt ( ) ; // Read the number of seconds
        int per_num = sc.nextInt ( ) ; // Read the number of periods
        int max_sec = sc.nextInt ( ) ; // Read the total number of seconds

        // Convert the last input (max_sec) to a double type and add 0.5 to it to get the maximum number of seconds with a fractional part
        double max_sec = ( double ) sc.nextInt ( ) + 0.5 ; // Read the total number of seconds and convert it to double

        // Initialize a counter variable ans_num to zero
        int ans_num = 0 ;

        // Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec. In each iteration of the loop, add per_num to ans_num
        for ( int i = sec ; i < max_sec ; i += sec ) {
            ans_num += per_num ;
        }

        // Print the result ans_num to the standard output stream
        System.out.println ( ans_num ) ;

        // Close the Scanner object to release the system resources
        sc.close ( ) ;
    }
}