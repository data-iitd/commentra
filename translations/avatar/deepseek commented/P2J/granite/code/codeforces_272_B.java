
import java.util.Scanner;

public class codeforces_272_B{
    public static void main(String[] args) {
        // Take input from the user
        Scanner scanner = new Scanner(System.in);
        scanner.nextInt();
        // Process the input and call nPairsWithCommonFX with the processed input
        System.out.println(nPairsWithCommonFX(scanner));
    }

    public static int nPairsWithCommonFX(Scanner scanner) {
        // Initialize a dictionary to store values grouped by their computed property
        Map<Integer, List<Integer>> storage = new HashMap<>();
        // List to store the computed property values
        List<Integer> FXs = new ArrayList<>();
        while (scanner.hasNextInt()) {
            // Take the next integer from the input
            int value = scanner.nextInt();
            // Compute the property for the current value
            int y = f(value);
            // If the property is not already in storage, add it with the current value
            if (!storage.containsKey(y)) {
                storage.put(y, new ArrayList<>());
                FXs.add(y);
            }
            // Append the current value to the list of values for this property
            storage.get(y).add(value);
        }
        // Calculate the number of pairs with common factor greater than 1
        int result = 0;
        for (int y : FXs) {
            result += storage.get(y).size() * storage.get(y).size();
        }
        return (result - FXs.size()) / 2;
    }

    public static int f(int n) {
        // Initialize y to 1, which will be the result for the property of n
        int y = 1;
        while (n!= 1) {
            if (n % 2!= 0) {
                y++;
            }
            n /= 2;
        }
        return y;
    }
}

