import java.io.*;
import java.util.*;
import java.math.*;
import java.util.concurrent.*;

class Main
{
    // Initialize BufferedReader and FastScanner for efficient input reading
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static FastScanner sc = new FastScanner(br);
    // Initialize PrintWriter for efficient output writing
    static PrintWriter out = new PrintWriter(System.out);
    // Initialize Random for generating random numbers
    static Random rnd = new Random();
    
    // Main method to execute the program
    public static void main(String args[]) throws Exception
    {
        // Read the number of elements
        int n = sc.nextInt();
        // Initialize prefix sum array
        long[] pre = new long[n+1];
        
        // Calculate prefix sum array
        for(int i = 1; i <= n; i++)
        {
            pre[i] = pre[i-1] + sc.nextLong();
        }
        
        // Initialize minimum difference to the maximum possible value
        long min = Long.MAX_VALUE;
        
        // Calculate the minimum absolute difference between the two parts of the array
        for(int i = 1; i < n; i++)
        {
            long val1 = pre[i], val2 = pre[n] - pre[i];
            min = Math.min(min, Math.abs(val1 - val2));
        }
        
        // Output the minimum difference
        out.println(min);
        // Close the output stream
        out.close();
    }
}

// FastScanner class to efficiently read input values
class FastScanner
{
    BufferedReader in;
    StringTokenizer st;

    // Constructor to initialize BufferedReader
    public FastScanner(BufferedReader in) {
        this.in = in;
    }
    
    // Method to read the next token
    public String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
    
    // Method to read the next word as a string
    public String next() throws Exception {
        return nextToken().toString();
    }
    
    // Method to read the next token as an integer
    public int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    // Method to read the next token as a long integer
    public long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    // Method to read the next token as a double
    public double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }
}
