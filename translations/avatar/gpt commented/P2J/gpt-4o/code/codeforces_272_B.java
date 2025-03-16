import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read input from the user (not stored, just consumed)
        new Scanner(System.in).nextLine();
        // Process the input sequence and print the number of pairs with common factors
        System.out.println(nPairsWithCommonFX(Arrays.stream(new Scanner(System.in).nextLine().split(" "))
                .mapToInt(Integer::parseInt).toArray()));
    }

    public static int nPairsWithCommonFX(int[] sequence) {
        // Initialize a map to store values based on their computed factor
        Map<Integer, List<Integer>> storage = new HashMap<>();
        // List to keep track of unique factors
        List<Integer> FXs = new ArrayList<>();

        // Iterate through each value in the input sequence
        for (int value : sequence) {
            // Compute the factor for the current value
            int y = f(value);
            // If the factor is not already in storage, add it
            if (!storage.containsKey(y)) {
                storage.put(y, new ArrayList<>(Arrays.asList(value))); // Store the value under its factor
                FXs.add(y); // Keep track of the unique factor
            } else {
                // If the factor already exists, append the value to the existing list
                storage.get(y).add(value);
            }
        }

        // Calculate the total number of pairs with common factors
        // The formula counts pairs and subtracts the number of single occurrences
        int totalPairs = 0;
        for (int key : FXs) {
            int size = storage.get(key).size();
            totalPairs += size * size; // Count pairs
        }
        for (int key : FXs) {
            totalPairs -= storage.get(key).size(); // Subtract single occurrences
        }
        return totalPairs / 2; // Return the final count of pairs
    }

    public static int f(int n) {
        // Initialize the factor count
        int y = 1;
        // Loop until n is reduced to 1
        while (n != 1) {
            // If n is odd, increment the factor count
            if (n % 2 != 0) {
                y++;
            }
            // Divide n by 2 to reduce it
            n /= 2;
        }
        // Return the total count of factors
        return y;
    }
}
<END-OF-CODE>
