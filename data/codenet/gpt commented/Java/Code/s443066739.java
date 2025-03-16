import java.io.*;
import java.util.*;
import java.math.*;
import java.util.concurrent.*;

class Main
{
    // Initialize BufferedReader for input, FastScanner for fast input processing, PrintWriter for output, and Random for random number generation
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static FastScanner sc = new FastScanner(br);
    static PrintWriter out = new PrintWriter(System.out);
    static Random rnd = new Random();
    
    public static void main(String args[]) throws Exception
    {
        // Read the number of elements
        int n = sc.nextInt();
        // Create a prefix sum array to store cumulative sums
        long[] pre = new long[n + 1];
        
        // Populate the prefix sum array
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + sc.nextLong(); // Calculate cumulative sum
        }
        
        // Initialize a variable to track the minimum difference
        long min = Long.MAX_VALUE;
        
        // Iterate through the prefix sums to find the minimum difference
        for (int i = 1; i < n; i++)
        {
            long val1 = pre[i]; // Sum of the first i elements
            long val2 = pre[n] - pre[i]; // Sum of the remaining elements
            
            // Update the minimum difference found
            min = Math.min(min, Math.abs(val1 - val2));
        }
        
        // Output the minimum difference and close the output stream
        out.println(min);
        out.close();
    }
}

// FastScanner class for efficient input reading
class FastScanner
{
    BufferedReader in; // BufferedReader for reading input
    StringTokenizer st; // Tokenizer for parsing input

    // Constructor to initialize the FastScanner with a BufferedReader
    public FastScanner(BufferedReader in) {
        this.in = in;
    }
    
    // Method to get the next token from input
    public String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine()); // Read a new line and tokenize it
        }
        return st.nextToken(); // Return the next token
    }
    
    // Method to get the next string from input
    public String next() throws Exception {
        return nextToken().toString(); // Return the next token as a string
    }
    
    // Method to get the next integer from input
    public int nextInt() throws Exception {
        return Integer.parseInt(nextToken()); // Parse and return the next token as an integer
    }

    // Method to get the next long from input
    public long nextLong() throws Exception {
        return Long.parseLong(nextToken()); // Parse and return the next token as a long
    }

    // Method to get the next double from input
    public double nextDouble() throws Exception {
        return Double.parseDouble(nextToken()); // Parse and return the next token as a double
    }
}
