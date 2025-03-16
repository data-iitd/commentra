public class Main {
    public static void main(String[] args) {
        // Read input from the user (not stored, just consumed)
        System.out.println("Enter a sequence of integers: ");
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        // Process the input sequence and return the number of pairs with common factors
        System.out.println(nPairsWithCommonFX(scanner.nextLine().split(" ")));
    }

    public static int nPairsWithCommonFX(String[] sequence) {
        // Initialize a dictionary to store values based on their computed factor
        Map<Integer, List<Integer>> storage = new HashMap<>();
        // List to keep track of unique factors
        List<Integer> FXs = new ArrayList<>();

        // Iterate through each value in the input sequence
        for (String value : sequence) {
            // Compute the factor for the current value
            int y = f(Integer.parseInt(value));
            // If the factor is not already in storage, add it
            if (!storage.containsKey(y)) {
                storage.put(y, new ArrayList<Integer>());
                FXs.add(y);
            }
            // If the factor already exists, append the value to the existing list
            storage.get(y).add(Integer.parseInt(value));
        }

        // Calculate the total number of pairs with common factors
        // The formula counts pairs and subtracts the number of single occurrences
        return (int) (FXs.stream().mapToInt(y -> storage.get(y).size() * storage.get(y).size()).sum() - FXs.stream().mapToInt(y -> storage.get(y).size()).sum()) / 2;
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
