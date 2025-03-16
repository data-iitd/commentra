// This is the main function that takes input and calls the helper function nPairsWithCommonFX
public static void main(String[] args) {
    // Read input from standard input
    Scanner scanner = new Scanner(System.in);
    scanner.nextLine();

    // Call the helper function with the sequence obtained from input
    int result = nPairsWithCommonFX(Arrays.stream(scanner.nextLine().split("\\s+")).mapToInt(Integer::parseInt).boxed().collect(Collectors.toList()));

    // Print the result
    System.out.println(result);
}

// This function takes a sequence as input and returns the number of pairs with common FX
public static int nPairsWithCommonFX(List<Integer> sequence) {
    // Initialize an empty dictionary to store FX values and their corresponding values
    Map<Integer, List<Integer>> storage = new HashMap<>();

    // Initialize an empty list to store unique FX values
    List<Integer> FXs = new ArrayList<>();

    // Iterate through each value in the sequence
    for (int value : sequence) {
        // Compute the FX value for the current value
        int fx = f(value);

        // If the FX value is not already in the dictionary, add it along with the value
        if (!storage.containsKey(fx)) {
            storage.put(fx, new ArrayList<>(Collections.singletonList(value)));
            FXs.add(fx);
        }

        // If the FX value is already in the dictionary, add the current value to the list of values for that FX
        else {
            storage.get(fx).add(value);
        }
    }

    // Calculate the result using the formula given in the problem statement
    int result = (int) FXs.stream().map(fx -> storage.get(fx).size() * storage.get(fx).size()).reduce(0, Integer::sum) - FXs.stream().map(fx -> storage.get(fx).size()).reduce(0, Integer::sum);

    // Return the result
    return result;
}

// This function takes an integer as input and returns its FX value
public static int f(int n) {
    // Initialize a variable to store the FX value
    int fx = 1;

    // Perform bitwise operations until the number is reduced to 1
    while (n!= 1) {
        // If the number is odd, increment the FX value
        if ((n & 1) == 1) {
            fx++;
        }

        // Divide the number by 2 to reduce it further
        n >>= 1;
    }

    // Return the final FX value
    return fx;
}

