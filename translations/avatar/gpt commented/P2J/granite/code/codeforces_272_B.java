
import java.util.Scanner;

public class codeforces_272_B{
    public static void main(String[] args) {
        // Read input from the user (not stored, just consumed)
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        // Process the input sequence and return the number of pairs with common factors
        System.out.println(nPairsWithCommonFX(toIntegerArray(scanner.nextLine().split(" "))));
    }

    public static int nPairsWithCommonFX(int[] sequence) {
        // Initialize a dictionary to store values based on their computed factor
        Map<Integer, List<Integer>> storage = new HashMap<>();
        // List to keep track of unique factors
        List<Integer> FXs = new ArrayList<>();

        // Iterate through each value in the input sequence
        for (int value : sequence) {
            // Compute the factor for the current value
            int y = f(value);
            // If the factor is not already in storage, add it
            if (!storage.containsKey(y)) {
                storage.put(y, new ArrayList<>());
                storage.get(y).add(value);
                FXs.add(y);
            } else {
                // If the factor already exists, append the value to the existing list
                storage.get(y).add(value);
            }
        }

        // Calculate the total number of pairs with common factors
        // The formula counts pairs and subtracts the number of single occurrences
        return (int) (FXs.stream().mapToLong(y -> (long) storage.get(y).size() * storage.get(y).size()).sum() - FXs.stream().mapToLong(storage::get).sum()) / 2;
    }

    public static int[] toIntegerArray(String[] array) {
        int[] result = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            result[i] = Integer.parseInt(array[i]);
        }
        return result;
    }

    public static int f(int n) {
        // Initialize the factor count
        int y = 1;
        // Loop until n is reduced to 1
        while (n!= 1) {
            // If n is odd, increment the factor count
            if (n % 2!= 0) {
                y++;
            }
            // Divide n by 2 to reduce it
            n /= 2;
        }
        // Return the total count of factors
        return y;
    }
}

