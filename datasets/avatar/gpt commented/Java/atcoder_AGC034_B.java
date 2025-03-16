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
        
        // Create a Scanner object for reading input
        Scanner in = new Scanner(inputStream); 
        
        // Create a PrintWriter object for writing output
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Create an instance of the BABC class to solve the problem
        BABC solver = new BABC(); 
        
        // Call the solve method with test number, input scanner, and output writer
        solver.solve(1, in, out); 
        
        // Close the output writer
        out.close(); 
    } 
    
    static class BABC { 
        public void solve(int testNumber, Scanner in, PrintWriter out) { 
            // Read the input string and replace occurrences of "BC" with "D"
            String s = in.next().replaceAll("BC", "D"); 
            
            // Initialize counters for 'A' and the result
            long cnt = 0; 
            long tmp = 0; 
            
            // Iterate through the modified string to count occurrences
            for (int i = 0; i < s.length(); i++) { 
                // Increment temporary counter for 'A'
                if (s.charAt(i) == 'A') { 
                    tmp++; 
                } 
                // Add the count of 'A's to the result when 'D' is encountered
                else if (s.charAt(i) == 'D') { 
                    cnt += tmp; 
                } 
                // Reset the temporary counter for any other character
                else { 
                    tmp = 0; 
                } 
            } 
            
            // Output the final count of valid pairs
            out.println(cnt); 
        } 
    } 
}
