
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; // Create a Scanner object to read input from the user
        
        double VP = in.nextInt ( ) ; // Read the initial speed of the police car (VP)
        double VD = in.nextInt ( ) ; // Read the initial speed of the thief car (VD)
        double T = in.nextInt ( ) ; // Read the initial head start time (T)
        double F = in.nextInt ( ) ; // Read the time it takes for the police car to refuel (F)
        double C = in.nextInt ( ) ; // Read the distance to catch the thief (C)
        
        if ( VD <= VP ) { 
            System.out.println ( "0" ) ; // If the thief's speed is not greater than the police's speed, print 0 and exit
            return ; 
        } 
        
        int answer = 0 ; // Initialize the answer variable to 0
        double start = T ; // Initialize the start variable to the initial head start time (T)
        
        while ( true ) { 
            double x = start * VP / ( VD - VP ) ; // Calculate the distance covered by the police car in one unit of time
            
            if ( ( start + x ) * VP >= C ) { 
                break ; // If the total distance covered by the police car is greater than or equal to C, break the loop
            } 
            
            start += 2 * x + F ; // Update the start variable by adding the distance covered and the refueling time
            answer ++ ; // Increment the answer variable by 1
        } 
        
        System.out.println ( answer ) ; // Print the final value of answer
    } 
}
