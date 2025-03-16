import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        int N, K, d, a;

        // Create a Scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Read input values for N and K
        N = scanner.nextInt();
        K = scanner.nextInt();

        // Initialize a map to store the frequency of each number
        Map<Integer, Integer> frequencyMap = new HashMap<>();

        // Initialize all elements of the map with zero frequency
        for (int i = 1; i <= N; i++) {
            frequencyMap.put(i, 0);
        }

        // Read K queries and process them
        for (int i = 0; i < K; i++) {
            // Read the length of the query
            d = scanner.nextInt();

            // Read the numbers in the query and increment their frequency in the map
            for (int j = 0; j < d; j++) {
                a = scanner.nextInt();
                frequencyMap.put(a, frequencyMap.get(a) + 1);
            }
        }

        // Initialize a variable named ans to store the answer
        int ans = 0;

        // Iterate through the map and check if the frequency of any number is zero
        // If yes, increment the value of ans
        for (int v : frequencyMap.values()) {
            if (v == 0) {
                ans++;
            }
        }

        // Print the final answer
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
