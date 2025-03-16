import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static final int INF = (int) Math.pow(10, 11); // Define a large constant for infinity

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int A = scanner.nextInt(); // Read the number of temples
        int B = scanner.nextInt(); // Read the number of shrines
        int Q = scanner.nextInt(); // Read the number of queries
        
        int[] s = new int[A + 2]; // Create an array for temples with extra space for boundaries
        s[0] = -INF; 
        s[A + 1] = INF; // Set boundary values
        for (int i = 1; i <= A; i++) {
            s[i] = scanner.nextInt(); // Read temple locations
        }

        int[] t = new int[B + 2]; // Create an array for shrines with extra space for boundaries
        t[0] = -INF; 
        t[B + 1] = INF; // Set boundary values
        for (int i = 1; i <= B; i++) {
            t[i] = scanner.nextInt(); // Read shrine locations
        }

        for (int i = 0; i < Q; i++) {
            int x = scanner.nextInt(); // Read the query point
            int b = Arrays.binarySearch(s, x); // Find closest temples
            if (b < 0) b = -b - 1; // Adjust if not found
            int d = Arrays.binarySearch(t, x); // Find closest shrines
            if (d < 0) d = -d - 1; // Adjust if not found
            
            int res = INF; // Initialize result with infinity
            for (int S : new int[]{s[b - 1], s[b]}) { // Check previous and current temple
                for (int T : new int[]{t[d - 1], t[d]}) { // Check previous and current shrine
                    int d1 = Math.abs(S - x) + Math.abs(T - S); // Calculate distances
                    int d2 = Math.abs(T - x) + Math.abs(S - T); // Calculate distances
                    res = Math.min(res, Math.min(d1, d2)); // Update result with minimum distance
                }
            }

            System.out.println(res); // Print the minimum distance for the query
        }
        
        scanner.close(); // Close the scanner
    }
}
