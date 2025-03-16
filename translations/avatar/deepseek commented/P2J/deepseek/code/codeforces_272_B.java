public class Main {
    public static void main(String[] args) {
        // Call the main function and print the result
        System.out.println(main());
    }

    public static int main() {
        // Take input from the user
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        // Process the input and call nPairsWithCommonFX with the processed input
        return nPairsWithCommonFX(Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray());
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
                storage.put(y, new ArrayList<>());
                FXs.add(y);
            }
            // Append the current value to the list of values for this property
            storage.get(y).add(value);
        }
        // Calculate the number of pairs with common factor greater than 1
        int count = 0;
        for (int y : FXs) {
            count += storage.get(y).size() * storage.get(y).size();
        }
        return (count - FXs.stream().mapToInt(y -> storage.get(y).size()).sum()) / 2;
    }

    public static int f(int n) {
        // Initialize y to 1, which will be the result for the property of n
        int y = 1;
        while (n != 1) {
            if (n % 2 != 0) {
                y += 1;
            }
            n /= 2;
        }
        return y;
    }
}
