import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of n and m from input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Initialize an output array with zeros, which will store the final results
        int[] out = new int[n];
        
        // Create a list 'comp' that holds values from 2 to n+1 (inclusive)
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
            int t = l - 1;
            
            // Continue processing while t is within the range [l-1, r-1]
            while (t < r) {
                // Get the next value from the 'comp' array
                int nextVal = comp[t];
                
                // If the current position in 'out' is still 0 and t is not equal to x-1
                if (out[t] == 0 && t != x - 1) {
                    // Set the output at position t to x
                    out[t] = x;
                }
                
                // Update the 'comp' array at position t based on the current value of t and x
                comp[t] = r + 1 > x ? x : r + 1;
                
                // Move to the next index as determined by nextVal
                t = nextVal - 1;
            }
        }
        
        // Print the final output array, unpacking the values to display them in a single line
        for (int value : out) {
            System.out.print(value + " ");
        }
    }
}
