import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // main method is the entry point of the program
    public static void main(String[] args) {
        // Initialize variables
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Allocate memory for h array
        int[] h = new int[n];
        
        // Read h array elements from standard input
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
            // Comment for the loop that reads h array elements
            // from standard input and stores them in the h array
        }
        
        // Initialize counter map
        Map<Integer, Object> counter = new HashMap<>();
        
        // Read m query pairs from standard input
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            // Check the condition for a and b
            if (h[a - 1] < h[b - 1]) {
                // Add a to the counter map if h[a-1] is smaller than h[b-1]
                counter.put(a, new Object());
            } else if (h[a - 1] > h[b - 1]) {
                // Add b to the counter map if h[a-1] is greater than h[b-1]
                counter.put(b, new Object());
            } else {
                // Add both a and b to the counter map if h[a-1] is equal to h[b-1]
                counter.put(a, new Object());
                counter.put(b, new Object());
            }
            // Comment for the loop that processes m query pairs
        }
        
        // Print the result
        System.out.println(n - counter.size());
        // Comment for the final print statement
    }
}
// <END-OF-CODE>
