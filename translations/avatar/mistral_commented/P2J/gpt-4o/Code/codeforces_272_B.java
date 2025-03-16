import java.util.*;

public class Main {
    // This is the main function that takes input and calls the helper function nPairsWithCommonFX
    public static void main(String[] args) {
        // Read input from standard input
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine(); // Read the first line (not used)

        // Call the helper function with the sequence obtained from input
        String[] input = scanner.nextLine().split(" ");
        int[] sequence = Arrays.stream(input).mapToInt(Integer::parseInt).toArray();
        int result = nPairsWithCommonFX(sequence);

        // Print the result
        System.out.println(result);
    }

    // This function takes a sequence as input and returns the number of pairs with common FX
    public static int nPairsWithCommonFX(int[] sequence) {
        // Initialize a HashMap to store FX values and their corresponding values
        Map<Integer, List<Integer>> storage = new HashMap<>();

        // Iterate through each value in the sequence
        for (int value : sequence) {
            // Compute the FX value for the current value
            int fx = f(value);

            // If the FX value is not already in the map, add it along with the value
            storage.putIfAbsent(fx, new ArrayList<>());
            storage.get(fx).add(value);
        }

        // Calculate the result using the formula given in the problem statement
        int result = 0;
        for (List<Integer> values : storage.values()) {
            int size = values.size();
            result += size * size; // Count pairs (size * size)
        }
        result -= storage.size(); // Subtract the number of unique FX values
        result /= 2; // Divide by 2 to get the number of pairs

        // Return the result
        return result;
    }

    // This function takes an integer as input and returns its FX value
    public static int f(int n) {
        // Initialize a variable to store the FX value
        int fx = 1;

        // Perform bitwise operations until the number is reduced to 1
        while (n != 1) {
            // If the number is odd, increment the FX value
            if (n % 2 != 0) {
                fx++;
            }

            // Divide the number by 2 to reduce it further
            n /= 2;
        }

        // Return the final FX value
        return fx;
    }
}

// <END-OF-CODE>
