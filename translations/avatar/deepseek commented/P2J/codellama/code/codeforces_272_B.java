public class Main {
    public static void main(String[] args) {
        // Take input from the user
        Scanner scanner = new Scanner(System.in);
        // Process the input and call nPairsWithCommonFX with the processed input
        System.out.println(nPairsWithCommonFX(scanner.nextLine().split(" ")));
    }

    public static int nPairsWithCommonFX(String[] sequence) {
        // Initialize a dictionary to store values grouped by their computed property
        Map<Integer, List<Integer>> storage = new HashMap<>();
        // List to store the computed property values
        List<Integer> FXs = new ArrayList<>();
        for (String value : sequence) {
            // Compute the property for the current value
            int y = f(Integer.parseInt(value));
            // If the property is not already in storage, add it with the current value
            if (!storage.containsKey(y)) {
                storage.put(y, new ArrayList<Integer>());
                FXs.add(y);
            }
            // Otherwise, append the current value to the list of values for this property
            storage.get(y).add(Integer.parseInt(value));
        }
        // Calculate the number of pairs with common factor greater than 1
        int result = 0;
        for (int y : FXs) {
            result += storage.get(y).size() * (storage.get(y).size() - 1);
        }
        return result / 2;
    }

    public static int f(int n) {
        // Initialize y to 1, which will be the result for the property of n
        int y = 1;
        while (n != 1) {
            if (n % 2 == 1) {
                y += 1;
            }
            n /= 2;
        }
        return y;
    }
}
