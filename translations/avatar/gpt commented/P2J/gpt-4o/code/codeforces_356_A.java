import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize an output array with zeros
        int[] out = new int[n];
        
        // Create an array 'comp' that holds values from 2 to n+1 (inclusive)
        int[] comp = new int[n];
        for (int i = 0; i < n; i++) {
            comp[i] = i + 2;
        }
        
        // Process each of the m operations
        for (int i = 0; i < m; i++) {
            // Read the values of l, r, and x for the current operation
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            int x = scanner.nextInt();
            
            // Start from the left index l
            int t = l;
            
            // Continue processing while t is within the range [l, r]
            while (t <= r) {
                // Get the next value from the 'comp' array
                int nextVal = comp[t - 1];
                
                // If the current position in 'out' is still 0 and t is not equal to x
                if (out[t - 1] == 0 && t != x) {
                    // Set the output at position t-1 to x
                    out[t - 1] = x;
                }
                
                // Update the 'comp' array at position t-1 based on the current value of t and x
                comp[t - 1] = (t >= x) ? (r + 1) : x;
                
                // Move to the next index as determined by nextVal
                t = nextVal;
            }
        }
        
        // Print the final output array
        for (int i = 0; i < n; i++) {
            System.out.print(out[i] + " ");
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
