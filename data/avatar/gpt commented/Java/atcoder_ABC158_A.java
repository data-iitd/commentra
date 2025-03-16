import java.io.OutputStream; 
import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Initialize input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        
        // Create a Scanner object for reading input and a PrintWriter for output
        Scanner in = new Scanner(inputStream); 
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Create an instance of the AStationAndBus class to solve the problem
        AStationAndBus solver = new AStationAndBus(); 
        
        // Call the solve method with test number 1, passing the input and output objects
        solver.solve(1, in, out); 
        
        // Close the PrintWriter to flush the output
        out.close(); 
    } 
    
    // Static inner class to handle the logic of the problem
    static class AStationAndBus { 
        public void solve(int testNumber, Scanner in, PrintWriter out) { 
            // Read the input string
            String s = in.next(); 
            
            // Check if the string contains both 'A' and 'B'
            if (s.contains("A") && s.contains("B")) { 
                // If both characters are present, print "Yes"
                out.println("Yes"); 
            } else { 
                // If either character is missing, print "No"
                out.println("No"); 
            } 
        } 
    } 
}
