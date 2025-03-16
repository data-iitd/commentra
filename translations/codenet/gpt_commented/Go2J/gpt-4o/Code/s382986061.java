import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    // Declare global variables for the number of elements (N), number of groups (K), 
    // and temporary variables (d for group size, a for element).
    static int N, K;
    static int d, a;

    public static void main(String[] args) {
        // Create a Scanner object for input.
        Scanner scanner = new Scanner(System.in);

        // Read the total number of elements (N) and the number of groups (K) from input.
        N = scanner.nextInt();
        K = scanner.nextInt();

        // Initialize a map to count occurrences of each element, with keys from 1 to N.
        Map<Integer, Integer> as = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            as.put(i, 0); // Set initial count of each element to 0.
        }

        // Process each group of elements.
        for (int i = 0; i < K; i++) {
            // Read the size of the current group (d).
            d = scanner.nextInt();
            // Read each element in the group and increment its count in the map.
            for (int j = 0; j < d; j++) {
                a = scanner.nextInt();
                as.put(a, as.get(a) + 1); // Increment the count for the element a.
            }
        }

        // Initialize a counter for elements that are not present in any group.
        int ans = 0;
        // Iterate through the counts of each element in the map.
        for (int v : as.values()) {
            // If an element's count is 0, it means it was not present in any group.
            if (v == 0) {
                ans++; // Increment the counter for missing elements.
            }
        }

        // Output the total count of elements that were not present in any group.
        System.out.println(ans);

        // Close the scanner.
        scanner.close();
    }
}
// <END-OF-CODE>
