import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.io.PrintWriter; 
import java.util.StringTokenizer; 

public class Main { 
    public static void main(String[] args) throws IOException { 
        // Initialize BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        
        // Initialize PrintWriter to output results to the console
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read the first line of input and tokenize it to get values for 'a' and 'tA'
        StringTokenizer st = new StringTokenizer(br.readLine()); 
        int a = Integer.parseInt(st.nextToken()); // 'a' represents some integer value
        int tA = Integer.parseInt(st.nextToken()); // 'tA' represents the time taken by 'a'
        
        // Read the second line of input and tokenize it to get values for 'b' and 'tB'
        st = new StringTokenizer(br.readLine()); 
        int b = Integer.parseInt(st.nextToken()); // 'b' represents another integer value
        int tB = Integer.parseInt(st.nextToken()); // 'tB' represents the time taken by 'b'
        
        // Read the third line of input which contains the time in "HH:MM" format
        String timing = br.readLine(); 
        
        // Parse the hours and minutes from the input time
        int hrs = Integer.parseInt(timing.substring(0, 2)); // Extract hours
        int mins = Integer.parseInt(timing.substring(3)); // Extract minutes
        
        // Convert the input time to total minutes since midnight
        int simDeparture = hrs * 60 + mins; 
        
        // Calculate the simulated arrival time by adding 'tA' to the departure time
        int simArrival = simDeparture + tA; 
        
        // Initialize a counter to keep track of valid bus schedules
        int counter = 0; 
        
        // Loop through the bus departure times starting from 5:00 AM (300 minutes) to 11:59 PM (1439 minutes)
        for (int i = 300; i < 1440; i += b) { 
            int busDeparture = i; // Current bus departure time
            int busArrival = i + tB; // Calculate bus arrival time
            
            // Check if the bus schedule overlaps with the simulated arrival time
            if (busDeparture >= simArrival || simDeparture >= busArrival) 
                continue; // If there's no overlap, skip to the next bus
            
            // If there is an overlap, increment the counter
            counter++; 
        } 
        
        // Output the total count of valid bus schedules
        pw.println(counter); 
        
        // Flush the output stream and close the PrintWriter
        pw.flush(); 
        pw.close(); 
    } 
}
