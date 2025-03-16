import java.util.Scanner ;

public class Main {
    public static void main ( String [ ] args ) {
        Scanner in = new Scanner ( System.in ) ; // Create a new Scanner object to read input from the standard input

        double VP = in.nextDouble() ; // Read VP
        double VD = in.nextDouble() ; // Read VD
        double T = in.nextDouble() ; // Read T
        double F = in.nextDouble() ; // Read F
        double C = in.nextDouble() ; // Read C

        if ( VD <= VP ) { // Check if VD is less than or equal to VP
            System.out.println ( "0" ) ; // If it is, then the answer is 0, and we return from the method
            in.close() ; // Close the Scanner object to free up system resources
            return ;
        }

        int answer = 0 ;
        double start = T ;

        while ( true ) { // Enter a while loop that runs indefinitely
            double x = start * VP / ( VD - VP ) ; // Calculate the time it takes to fill a volume VP with the given rate VP / (VD - VP)

            if ( ( start + x ) * VP >= C ) { // Check if the total volume filled after start + x is greater than or equal to C
                break ; // If it is, then we break out of the loop
            }

            start += 2 * x + F ; // Update the value of start by adding 2 * x + F to it
            answer ++ ; // Increment the value of answer by 1
        }

        System.out.println ( answer ) ; // Print the value of answer to the standard output
        in.close() ; // Close the Scanner object to free up system resources
    }
}