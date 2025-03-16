import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Read the number of elements
        int m = scanner.nextInt(); // Read the number of comparisons
        int[] h = new int[n]; // Create an array to store the heights of the elements
        
        for (int i = 0; i < n; i++) {
            h[i] = scanner.nextInt(); // Read the heights of the elements
        }
        
        Map<Integer, Boolean> counter = new HashMap<>(); // Create a map to keep track of elements that cannot be the highest
        
        for (int i = 0; i < m; i++) {
            int a = scanner.nextInt(); // Read the first index of the comparison
            int b = scanner.nextInt(); // Read the second index of the comparison
            
            if (h[a - 1] < h[b - 1]) { // Check if the height of the first element is less than the second
                counter.put(a, true); // Mark the first element as not being the highest
            } else if (h[a - 1] > h[b - 1]) { // Check if the height of the first element is greater than the second
                counter.put(b, true); // Mark the second element as not being the highest
            } else { // If the heights of the two elements are equal
                counter.put(a, true); // Mark both elements as not being the highest
                counter.put(b, true);
            }
        }
        
        System.out.println(n - counter.size()); // Print the number of elements that cannot be the highest
        scanner.close();
    }
}

// <END-OF-CODE>
