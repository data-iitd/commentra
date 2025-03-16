// Importing necessary packages
import java.util.*;
import java.io.*;

public class Main {
    // Main function
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        
        solve(br, wr); // Call the solve function
        wr.flush(); // Flush the writer buffer
    }

    private static void solve(BufferedReader br, PrintWriter wr) throws IOException {
        int n = getInt(br); // Read the number of elements in the array
        int[] as = getIntArray(br, n); // Read the array elements

        // Initialize an array xs of size n
        int[] xs = new int[n];
        // Iterate through the array as and assign the value xs[i]
        for (int i = 0; i < n; i++) {
            xs[i] = as[i] - i + 1; // Assign the value xs[i] = a - i + 1
        }
        // Sort the array xs in ascending order
        Arrays.sort(xs);

        // Assign the middle element of the sorted array xs to variable b
        int b = xs[n / 2];
        // Initialize variable ans with 0
        int ans = 0;
        // Iterate through the array xs and calculate the absolute difference between each element and b
        for (int x : xs) {
            ans += Math.abs(x - b); // Calculate the absolute difference and add it to ans
        }
        // Print the answer
        wr.println(ans);
    }

    private static int getInt(BufferedReader br) throws IOException {
        // Function to read an integer from standard input
        return Integer.parseInt(br.readLine().trim()); // Read and parse the integer
    }

    private static int[] getIntArray(BufferedReader br, int n) throws IOException {
        // Function to read an array of n integers from standard input
        int[] ret = new int[n]; // Initialize the array with size n
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            ret[i] = Integer.parseInt(st.nextToken()); // Read each integer and assign it to the corresponding index in the array
        }
        return ret;
    }
}

// <END-OF-CODE>
