public class Main {
    public static void main(String[] args) {
        // Take input from the user
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        // Process the input and call nPairsWithCommonFX with the processed input
        System.out.println(nPairsWithCommonFX(Arrays.stream(sc.nextLine().split("\\s+")).mapToInt(Integer::parseInt).boxed().collect(Collectors.toList())));
    }

    public static int nPairsWithCommonFX(List<Integer> sequence) {
        // Initialize a dictionary to store values grouped by their computed property
        Map<Integer, List<Integer>> storage = new HashMap<>();
        // List to store the computed property values
        List<Integer> FXs = new ArrayList<>();
        for (int value : sequence) {
            // Compute the property for the current value
            int y = f(value);
            // If the property is not already in storage, add it with the current value
            if (!storage.containsKey(y)) {
                storage.put(y, new ArrayList<>(Collections.singletonList(value)));
                FXs.add(y);
            } else {
                // Otherwise, append the current value to the list of values for this property
                storage.get(y).add(value);
            }
        }
        // Calculate the number of pairs with common factor greater than 1
        return (FXs.stream().map(y -> storage.get(y).size() * storage.get(y).size()).reduce(0, Integer::sum) - FXs.stream().map(y -> storage.get(y).size()).reduce(0, Integer::sum)) / 2;
    }

    public static int f(int n) {
        // Initialize y to 1, which will be the result for the property of n
        int y = 1;
        while (n!= 1) {
            if (n % 2!= 0) {
                y += 1;
            }
            n /= 2;
        }
        return y;
    }
}

