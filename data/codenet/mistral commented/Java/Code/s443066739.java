
import java.io.*;
import java.util.*;
import java.math.*;
import java.util.concurrent.*;

class Main
{
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	static FastScanner sc=new FastScanner(br);
    static PrintWriter out=new PrintWriter(System.out);
	static Random rnd=new Random();
	
    public static void main(String args[]) throws Exception
    {
        // Read the number of test cases
        int n=sc.nextInt();

        // Initialize an array 'pre' of size 'n+1' to store the prefix sums
        long[] pre=new long[n+1];

        // Read and calculate the prefix sums for all the given numbers
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+sc.nextLong(); // Calculate the prefix sum for the current number by adding it to the previous prefix sum
        }

        // Initialize a variable 'min' with a large value to store the minimum difference between any two prefix sums
        long min=Long.MAX_VALUE;

        // Iterate through all the prefix sums except the last one
        for(int i=1;i<n;i++)
        {
            long val1=pre[i]; // Store the prefix sum up to the current index
            long val2=pre[n]-pre[i]; // Calculate the prefix sum from the last index to the current index

            // Update the minimum difference if the current difference is smaller
            min=Math.min(min,Math.abs(val1-val2));
        }

        // Print the minimum difference
        out.println(min);
        out.close();
    }
}

class FastScanner
{
    BufferedReader in;
    StringTokenizer st;

    public FastScanner(BufferedReader in) {
        this.in = in;
    }
	
    public String nextToken() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return st.nextToken();
    }
	
    public String next() throws Exception {
		return nextToken().toString();
	}
	
    public int nextInt() throws Exception {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws Exception {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws Exception {
        return Double.parseDouble(nextToken());
    }
}