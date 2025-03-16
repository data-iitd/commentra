// Read input values N and X from the user
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int X = sc.nextInt();

// Define a function to perform calculations on the input list
public int calc(int[] x) {
    // Define a helper function to process the list y
    public int[] sub(int[] y, boolean debug) {
        // If debug mode is on, print the current state of y
        if (debug) {
            System.out.println("D " + Arrays.toString(y));
        }
        // Reduce the list y until it has only one element
        while (y.length > 1) {
            // Replace y with the second largest element of every three consecutive elements
            y = Arrays.stream(y).mapToObj(i -> Arrays.stream(Arrays.copyOfRange(y, i, i + 3)).max().getAsInt()).mapToInt(i -> i).toArray();
            // If debug mode is on, print the current state of y
            if (debug) {
                System.out.println("D " + Arrays.toString(y));
            }
        }
        return y;
    }
    
    // Call the helper function to process x
    int[] y = sub(x, true);
    
    // If the final result is 2, perform additional processing
    if (y[0] == 2) {
        // Placeholder for potential future logic
        sub(x, true);  // Call sub with debug mode on
        System.out.println("= " + Arrays.toString(x));  // Print the original list x
    }
    
    // Return the final processed value
    return y[0];
}

// Check specific conditions based on the value of X
if (X == 1 || X == N * 2 - 1) {
    // If X is at the boundaries, print "No"
    System.out.println("No");
} else {
    // If X is within the valid range, print "Yes"
    System.out.println("Yes");
    
    // Handle the case where X is N * 2 - 2
    if (X == N * 2 - 2) {
        // Create a list xs with specific ranges
        int[] xs = new int[N - 1 + N - 1];
        for (int i = 0; i < N - 1; i++) {
            xs[i] = i;
        }
        for (int i = 0; i < N - 1; i++) {
            xs[N - 1 + i] = N - 1 - i;
        }
    } else {
        // Create a list ys with specific ranges and then construct xs
        int[] ys = new int[N - 3 + 3];
        for (int i = 0; i < N - 3; i++) {
            ys[i] = i + 1;
        }
        ys[N - 3] = X + 2;
        ys[N - 2] = X - 1;
        ys[N - 1] = X;
        ys[N - 3 + 1] = X + 1;
        for (int i = 0; i < N - 3; i++) {
            ys[N - 3 + 2 + i] = N * 2 - 1 - i;
        }
        // Print each element in the final list xs
        for (int x : xs) {
            System.out.println(x);
        }
    }
}

