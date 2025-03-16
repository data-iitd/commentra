import java.io.*;
import java.util.*;

public class Main {
    // solve function computes the minimum total distance to a median value
    static void solve() throws IOException {
        // Read the number of elements
        int n = getInt();
        // Read the integer slice of size n
        int[] as = getIntArray(n);

        // Create a new array to store adjusted values
        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            // Adjust each element by subtracting its index and adding 1
            xs[i] = as[i] - i + 1;
        }
        // Sort the adjusted values
        Arrays.sort(xs);

        // Find the median value from the sorted array
        int b = xs[n / 2];
        int ans = 0;
        // Calculate the total distance from each element to the median
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        // Output the result
        wr.write(ans + "\n");
    }

    // abs function returns the absolute value of an integer
    static int abs(int n) {
        return n < 0 ? -n : n;
    }

    // -----------------------------------------

    static final long inf = 1L << 60; // A constant representing infinity
    // static final int mod = 1000000007; // Uncomment if modular arithmetic is needed

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

    // main function initializes input/output and calls the solve function
    public static void main(String[] args) throws IOException {
        // Call the solve function to perform the main logic
        solve();
        // Flush the output buffer
        wr.flush();
    }

    // getInt reads an integer from input
    static int getInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    // getIntArray reads an array of integers from input
    static int[] getIntArray(int n) throws IOException {
        int[] ret = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            ret[i] = Integer.parseInt(st.nextToken()); // Read each integer
        }
        return ret;
    }

    // getString reads a string from input
    static String getString() throws IOException {
        return br.readLine();
    }
}
