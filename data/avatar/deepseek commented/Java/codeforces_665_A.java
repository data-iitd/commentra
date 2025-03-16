
import java.io.BufferedReader ; import java.io.IOException ; import java.io.InputStreamReader ; import java.io.PrintWriter ; import java.util.StringTokenizer ; 

public class Main { 
    public static void main ( String [ ] args ) throws IOException { 
        // Create BufferedReader to read input from System.in
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        // Create PrintWriter to write output to System.out
        PrintWriter pw = new PrintWriter ( System.out ) ; 
        
        // Read the first train's details
        StringTokenizer st = new StringTokenizer ( br.readLine ( ) ) ; 
        int a = Integer.parseInt ( st.nextToken ( ) ) ; // Train number a
        int tA = Integer.parseInt ( st.nextToken ( ) ) ; // Travel time for train a
        
        // Read the second train's details
        st = new StringTokenizer ( br.readLine ( ) ) ; 
        int b = Integer.parseInt ( st.nextToken ( ) ) ; // Train number b
        int tB = Integer.parseInt ( st.nextToken ( ) ) ; // Travel time for train b
        
        // Read the current timing
        String timing = br.readLine ( ) ; 
        int hrs = Integer.parseInt ( timing.substring ( 0 , 2 ) ) ; // Extract hour from timing
        int mins = Integer.parseInt ( timing.substring ( 3 ) ) ; // Extract minute from timing
        
        // Calculate the simulated departure and arrival times for train a
        int simDeparture = hrs * 60 + mins ; 
        int simArrival = simDeparture + tA ; 
        
        // Initialize counter to keep track of conflicts
        int counter = 0 ; 
        
        // Iterate through the bus schedule, checking for conflicts
        for ( int i = 300 ; i < 1440 ; i += b ) { 
            int busDeparture = i ; // Bus departure time
            int busArrival = i + tB ; // Bus arrival time
            
            // Check if there's a conflict (bus and train schedules overlap)
            if ( busDeparture >= simArrival || simDeparture >= busArrival ) continue ; 
            
            // Increment counter if a conflict is found
            counter ++ ; 
        } 
        
        // Print the number of conflicts found
        pw.println ( counter ) ; 
        pw.flush ( ) ; 
        pw.close ( ) ; 
    } 
}
