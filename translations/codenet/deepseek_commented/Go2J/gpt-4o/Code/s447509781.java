import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine()); // Read the number of elements
        long[] s = new long[n]; // Array to store integers
        StringTokenizer st = new StringTokenizer(reader.readLine());
        
        for (int i = 0; i < n; i++) {
            s[i] = Long.parseLong(st.nextToken()); // Read the array of integers
        }
        
        boolean[] u = new boolean[n]; // Initialize a boolean array to track visited positions
        long m = 0, f;
        
        // Iterate over possible values of c to find the maximum sum
        for (int c = 1; c < n - 1; c++) {
            f = 0;
            // Iterate over possible multiples of c
            for (int k = 0; c < n - 1 - k * c; k++) {
                u[k * c] = true; // Mark the position as visited
                if (u[n - 1 - k * c]) break; // If the position is already visited, break the loop
                f += s[n - 1 - k * c] + s[k * c]; // Add the values at the current positions
                if (m < f) m = f; // Update the maximum sum if the current sum is greater
            }
            // Reset the boolean array for the next value of c
            for (int k = 0; k * c < n - 1; k++) {
                u[k * c] = false;
            }
        }
        System.out.println(m); // Print the maximum sum found
    }
}
