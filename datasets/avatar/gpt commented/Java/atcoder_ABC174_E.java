import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStream; 
import java.io.InputStreamReader; 
import java.io.OutputStream; 
import java.io.PrintWriter; 
import java.util.StringTokenizer; 

public class Main { 
    public static void main(String[] args) { 
        // Set up input and output streams
        InputStream inputStream = System.in; 
        OutputStream outputStream = System.out; 
        
        // Initialize InputReader for reading input and PrintWriter for output
        InputReader in = new InputReader(inputStream); 
        PrintWriter out = new PrintWriter(outputStream); 
        
        // Create an instance of Solution to solve the problem
        Solution sol = new Solution(); 
        sol.solve(in, out); 
        
        // Close the output stream
        out.close(); 
    } 

    private static class Solution { 
        private void solve(InputReader in, PrintWriter out) { 
            // Read the number of logs and the value of k
            int n = in.nextInt(), k = in.nextInt(); 
            
            // Read the lengths of the logs into an array
            int[] logsLength = in.readArray(n); 
            
            // Initialize binary search bounds
            int min = 1, max = (int) 1e9 + 1000; 
            
            // Perform binary search to find the minimum possible length
            while (min < max) { 
                int mid = (min + max) / 2; 
                
                // Check if it's possible to cut the logs with the current mid length
                if (nei(mid, logsLength, k)) 
                    max = mid; // If possible, search in the lower half
                else 
                    min = mid + 1; // Otherwise, search in the upper half
            } 
            
            // Output the minimum length found
            out.println(min); 
        } 

        // Helper method to determine if logs can be cut with the given mid length
        private boolean nei(int mid, int[] logsLength, int k) { 
            for (int log : logsLength) 
                k -= (log + mid - 1) / mid - 1; // Calculate the number of cuts needed
            
            // Return true if we can make the cuts within the limit of k
            return k >= 0; 
        } 
    } 

    private static class InputReader { 
        private BufferedReader reader; 
        private StringTokenizer tokenizer; 
        
        // Constructor to initialize the BufferedReader
        private InputReader(InputStream stream) { 
            reader = new BufferedReader(new InputStreamReader(stream), 32768); 
            tokenizer = null; 
        } 
        
        // Method to read the next token from input
        private String next() { 
            // Read a new line if the tokenizer is empty
            while (tokenizer == null || !tokenizer.hasMoreTokens()) { 
                try { 
                    tokenizer = new StringTokenizer(reader.readLine()); 
                } catch (IOException e) { 
                    throw new RuntimeException(e); 
                } 
            } 
            return tokenizer.nextToken(); 
        } 
        
        // Method to read the next integer from input
        private int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        
        // Method to read an array of integers from input
        private int[] readArray(int n) { 
            int[] a = new int[n]; 
            for (int i = 0; i < n; ++i) 
                a[i] = nextInt(); // Fill the array with integers
            return a; 
        } 
    } 
}
