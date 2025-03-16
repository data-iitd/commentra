import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStream; 
import java.io.InputStreamReader; 
import java.io.OutputStream; 
import java.io.PrintWriter; 
import java.util.Arrays; 
import java.util.StringTokenizer; 

public class Main { 
    public static void main(String[] args) { 
        // Set up input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        
        // Create an InputReader to read input from the input stream
        InputReader in = new InputReader(inputStream); 
        
        // Create a PrintWriter to write output to the output stream
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Create an instance of the Solution class to solve the problem
        Solution sol = new Solution(); 
        
        // Call the solve method to process the input and produce output
        sol.solve(in, out); 
        
        // Close the PrintWriter to flush the output
        out.close(); 
    } 

    private static class Solution { 
        private void solve(InputReader in, PrintWriter out) { 
            // Read the number of elements (n) and the number of smallest elements to sum (k)
            int n = in.ni(), k = in.ni(); 
            
            // Initialize an array to hold the input numbers
            int[] a = new int[n]; 
            
            // Read n integers from input and store them in the array
            for (int i = 0; i < n; ++i) 
                a[i] = in.ni(); 
            
            // Sort the array in parallel to arrange numbers in ascending order
            Arrays.parallelSort(a); 
            
            // Initialize a variable to hold the sum of the smallest k elements
            int ans = 0; 
            
            // Sum the first k elements of the sorted array
            for (int i = 0; i < k; ++i) 
                ans += a[i]; 
            
            // Output the result (sum of the smallest k elements)
            out.println(ans); 
        } 
    } 

    private static class InputReader { 
        private BufferedReader reader; 
        private StringTokenizer tokenizer; 
        
        // Constructor to initialize the InputReader with an InputStream
        private InputReader(InputStream stream) { 
            reader = new BufferedReader(new InputStreamReader(stream), 32768); 
            tokenizer = null; 
        } 
        
        // Method to read the next token as a String
        private String n() { 
            // Read a new line if the tokenizer is null or has no more tokens
            while (tokenizer == null || !tokenizer.hasMoreTokens()) { 
                try { 
                    tokenizer = new StringTokenizer(reader.readLine()); 
                } catch (IOException e) { 
                    throw new RuntimeException(e); 
                } 
            } 
            return tokenizer.nextToken(); 
        } 
        
        // Method to read the next token as an integer
        private int ni() { 
            return Integer.parseInt(n()); 
        } 
    } 
}
