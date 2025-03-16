import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize input reader
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the number of elements
        int n = Integer.parseInt(reader.readLine());
        long[] s = new long[n];
        
        // Read the array of integers
        StringTokenizer st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            s[i] = Long.parseLong(st.nextToken());
        }
        
        // Create a boolean array to track used indices
        boolean[] u = new boolean[n];
        
        // Initialize variables to store the maximum sum and a temporary sum
        long m = 0, f;
        
        // Iterate through possible values of c from 1 to n-2
        for (int c = 1; c < n - 1; c++) {
            f = 0; // Reset the temporary sum for each c
            
            // Iterate to find pairs of indices based on the current value of c
            for (int k = 0; c < n - 1 - k * c; k++) {
                u[k * c] = true; // Mark the current index as used
                
                // Break if the corresponding index is already used
                if (u[n - 1 - k * c]) break;
                
                // Calculate the sum of the elements at the current indices
                f += s[n - 1 - k * c] + s[k * c];
                
                // Update the maximum sum if the current sum is greater
                if (m < f) m = f;
            }
            
            // Reset the used indices for the next iteration of c
            for (int k = 0; k * c < n - 1; k++) {
                u[k * c] = false;
            }
        }
        
        // Print the maximum sum found
        System.out.println(m);
    }
}
