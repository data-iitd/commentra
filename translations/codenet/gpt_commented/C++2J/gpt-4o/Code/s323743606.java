import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a map to store the minimum price for each weight
        Map<Integer, Integer> m = new HashMap<>();

        // Iterate over possible quantities of items weighing 200 units
        for (int i = 0; i * 200 < 5001; i++) {
            // Iterate over possible quantities of items weighing 300 units
            for (int j = 0; j * 300 < 5001; j++) {
                // Iterate over possible quantities of items weighing 500 units
                for (int k = 0; k * 500 < 5001; k++) {
                    // Calculate the total weight based on the quantities of items
                    int w = i * 200 + j * 300 + k * 500;

                    // Calculate the price based on the quantities of items
                    int p = (i / 5 * 5 * 380 * 0.8) + (i % 5 * 380)
                          + (j / 4 * 4 * 550 * 0.85) + (j % 4 * 550)
                          + (k / 3 * 3 * 850 * 0.88) + (k % 3 * 850);

                    // Update the map with the minimum price for the calculated weight
                    if (m.containsKey(w)) {
                        m.put(w, Math.min(m.get(w), p)); // If weight already exists, take the minimum price
                    } else {
                        m.put(w, p); // If weight does not exist, set the price
                    }
                }
            }
        }

        // Read input weights and output the corresponding minimum prices
        Scanner scanner = new Scanner(System.in);
        int n;
        while ((n = scanner.nextInt()) != 0) {
            System.out.println(m.getOrDefault(n, 0)); // Output the minimum price for the given weight
        }
        scanner.close();
    }
}
// <END-OF-CODE>
