import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt(); // Read the number of elements
        int K = scanner.nextInt(); // Read the number of days
        
        Map<Integer, Integer> occurrences = new HashMap<>(); // Create a map to keep track of occurrences of each element
        
        for (int i = 1; i <= N; i++) {
            occurrences.put(i, 0); // Initialize all elements to zero in the map
        }
        
        for (int i = 0; i < K; i++) {
            int d = scanner.nextInt(); // Read the number of elements chosen on the i-th day
            for (int j = 0; j < d; j++) {
                int a = scanner.nextInt(); // Read the elements chosen on the i-th day
                occurrences.put(a, occurrences.get(a) + 1); // Increment the count of the chosen element in the map
            }
        }
        
        int ans = 0; // Initialize the answer variable to count unchosen elements
        for (int count : occurrences.values()) {
            if (count == 0) {
                ans++; // Increment the answer if an element was not chosen
            }
        }
        
        System.out.println(ans); // Print the number of unchosen elements
        scanner.close();
    }
}
// <END-OF-CODE>
