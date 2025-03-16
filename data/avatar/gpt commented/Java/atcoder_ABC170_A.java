import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.PrintWriter; 

public class Main { 
    public static void main(String[] args) throws IOException { 
        // Create a BufferedReader to read input from the standard input stream
        BufferedReader br = new BufferedReader(new java.io.InputStreamReader(System.in)); 
        
        // Create a PrintWriter to output results to the standard output stream
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read a line of input, split it into an array of strings based on spaces
        String[] input_array = br.readLine().split(" "); 
        
        // Initialize a counter to keep track of the number of non-zero inputs
        int result = 0; 
        
        // Iterate through each string in the input array
        for (String str : input_array) { 
            // Increment the counter for each input
            result += 1; 
            
            // If the input is "0", break out of the loop
            if ("0".equals(str)) break; 
        } 
        
        // Print the result, which is the count of non-zero inputs before the first "0"
        pw.println(result); 
        
        // Close the BufferedReader to free up resources
        br.close(); 
        
        // Close the PrintWriter to ensure all output is flushed and resources are freed
        pw.close(); 
    } 
}
