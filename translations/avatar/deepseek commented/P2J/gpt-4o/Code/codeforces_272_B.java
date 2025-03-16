import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Take input from the user
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        // Process the input and call nPairsWithCommonFX with the processed input
        System.out.println(nPairsWithCommonFX(Arrays.stream(input.split(" "))
                .mapToInt(Integer::parseInt)
                .toArray()));
    }

    public static int nPairsWithCommonFX(int[] sequence) {
        // Initialize a dictionary to store values grouped by their computed property
        Map<Integer, List<Integer>> storage = new HashMap<>();
        // List to store the computed property values
        List<Integer> FXs = new ArrayList<>();
        
        for (int value : sequence) {
            // Compute the property for the current value
            int y = f(value);
            // If the property is not already in storage, add it with the current value
            if (!storage.containsKey(y)) {
                storage.put(y, new ArrayList<>(Arrays.asList(value)));
                FXs.add(y);
            } else {
                // Otherwise, append the current value to the list of values for this property
                storage.get(y).add(value);
            }
        }
        
        // Calculate the number of pairs with common factor greater than 1
        int totalPairs = 0;
        for (int y : FXs) {
            int count = storage.get(y).size();
            totalPairs += count * count;
        }
        
        int totalSingle = FXs.stream().mapToInt(y -> storage.get(y).size()).sum();
        return (totalPairs - totalSingle) / 2;
    }

    public static int f(int n) {
        // Initialize y to 1, which will be the result for the property of n
        int y = 1;
        while (n != 1) {
            if (n % 2 != 0) {
                y++;
            }
            n /= 2;
        }
        return y;
    }
}
