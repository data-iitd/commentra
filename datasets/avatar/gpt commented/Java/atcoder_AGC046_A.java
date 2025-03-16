import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.io.PrintWriter; 
import java.util.*; 

public class Main { 
    public static void main(String[] args) throws IOException { 
        // Create a FastReader object to read input efficiently
        FastReader sc = new FastReader(); 
        // Create a PrintWriter object to output results
        PrintWriter pw = new PrintWriter(System.out); 
        
        // Read an integer input from the user
        int x = sc.nextInt(); 
        // Initialize a counter to keep track of the number of rotations
        int count = 0; 
        // Store the original value of x for later use
        int tmp = x; 
        // Reset x to 0 for the rotation calculation
        x = 0; 
        
        // Loop until x completes a full rotation (360 degrees)
        while (x != 360) { 
            // Increment x by the original input value
            x = x + tmp; 
            // If x exceeds 360, wrap it around by subtracting 360
            if (x > 360) { 
                x = x - 360; 
            } 
            // Increment the count of rotations
            count++; 
        } 
        
        // Output the total number of rotations needed to reach 360 degrees
        System.out.println(count); 
    } 
} 

// FastReader class for efficient input reading
class FastReader { 
    BufferedReader br; 
    StringTokenizer st; 
    
    // Constructor initializes the BufferedReader
    public FastReader() { 
        br = new BufferedReader(new InputStreamReader(System.in)); 
    } 
    
    // Method to read the next token as a String
    String next() { 
        // Continue reading until there are more tokens available
        while (st == null || !st.hasMoreElements()) { 
            try { 
                // Read a line and tokenize it
                st = new StringTokenizer(br.readLine()); 
            } catch (IOException e) { 
                e.printStackTrace(); 
            } 
        } 
        // Return the next token
        return st.nextToken(); 
    } 
    
    // Method to read the next token as an integer
    int nextInt() { 
        return Integer.parseInt(next()); 
    } 
    
    // Method to read the next token as a long
    long nextLong() { 
        return Long.parseLong(next()); 
    } 
    
    // Method to read the next token as a double
    double nextDouble() { 
        return Double.parseDouble(next()); 
    } 
    
    // Method to read the next line as a String
    String nextLine() { 
        String str = ""; 
        try { 
            str = br.readLine(); 
        } catch (IOException e) { 
            e.printStackTrace(); 
        } 
        return str; 
    } 
}
