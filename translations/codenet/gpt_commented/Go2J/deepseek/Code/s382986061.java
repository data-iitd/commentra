import java.util.Scanner;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the total number of elements (N) and the number of groups (K) from input.
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        
        // Initialize a map to count occurrences of each element, with keys from 1 to N.
        HashMap<Integer, Integer> as = new HashMap<>();
        for (int i = 1; i <= N; i++) {
            as.put(i, 0); // Set initial count of each element to 0.
        }
        
        // Process each group of elements.
        for (int i = 0; i < K; i++) {
            // Read the size of the current group (d).
            int d = scanner.nextInt();
            // Read each element in the group and increment its count in the map.
            for (int j = 0; j < d; j++) {
                int a = scanner.nextInt();
                as.put(a, as.get(a) + 1); // Increment the count for the element a.
            }
        }
        
        // Initialize a counter for elements that are not present in any group.
        int ans = 0;
        // Iterate through the counts of each element in the map.
        for (int value : as.values()) {
            // If an element's count is 0, it means it was not present in any group.
            if (value == 0) {
                ans++; // Increment the counter for missing elements.
            }
        }
        
        // Output the total count of elements that were not present in any group.
        System.out.println(ans);
    }
}
