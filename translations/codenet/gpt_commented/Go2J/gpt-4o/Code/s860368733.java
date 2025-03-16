import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of elements (n) and the number of comparisons (m)
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Create an array to hold the heights of n elements
        int[] h = new int[n];
        
        // Read the heights of the n elements from standard input
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt();
        }
        
        // Declare variables for the two elements to compare (a and b)
        int a, b;
        
        // Create a map to keep track of unique elements that are involved in comparisons
        Map<Integer, Boolean> counter = new HashMap<>();
        
        // Loop through m comparisons
        for (int i = 0; i < m; i++) {
            // Read the indices of the two elements to compare
            a = scanner.nextInt();
            b = scanner.nextInt();
            
            // Compare the heights of the two elements
            if (h[a - 1] < h[b - 1]) {
                // If height of a is less than height of b, add a to the counter
                counter.put(a, true);
            } else if (h[a - 1] > h[b - 1]) {
                // If height of a is greater than height of b, add b to the counter
                counter.put(b, true);
            } else {
                // If heights are equal, add both a and b to the counter
                counter.put(a, true);
                counter.put(b, true);
            }
        }
        
        // Print the number of elements that were not involved in any comparisons
        System.out.println(n - counter.size());
        
        scanner.close();
    }
}
// <END-OF-CODE>
