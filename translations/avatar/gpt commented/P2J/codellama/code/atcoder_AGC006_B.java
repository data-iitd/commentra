// Read input values N and X from the user
Scanner sc = new Scanner(System.in);
int N = sc.nextInt();
int X = sc.nextInt();

// Define a function to perform calculations on the input list
void calc(int[] x) {
    // Define a helper function to process the list y
    void sub(int[] y, boolean debug) {
        // If debug mode is on, print the current state of y
        if (debug) {
            System.out.println("D " + Arrays.toString(y));
        }
        // Reduce the list y until it has only one element
        while (y.length > 1) {
            // Replace y with the second largest element of every three consecutive elements
            y = Arrays.stream(y).map(i -> {
                int[] z = new int[3];
                z[0] = i;
                z[1] = y[i + 1];
                z[2] = y[i + 2];
                return Math.max(z[1], z[2]);
            }).toArray();
            // If debug mode is on, print the current state of y
            if (debug) {
                System.out.println("D " + Arrays.toString(y));
            }
        }
    }
    
    // Call the helper function to process x
    int[] y = sub(x, false);
    
    // If the final result is 2, perform additional processing
    if (y[0] == 2) {
        // Placeholder for potential future logic
        sub(x, true);
        System.out.println("=" + Arrays.toString(x));
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
        int[] xs = IntStream.range(N - 1, X + 2).toArray();
        xs = Arrays.stream(xs).map(i -> i == X + 1 ? X - 1 : i).toArray();
    } else {
        // Create a list ys with specific ranges and then construct xs
        int[] ys = IntStream.range(1, X - 1).toArray();
        ys = Arrays.stream(ys).map(i -> i == X - 2 ? X + 2 : i).toArray();
        xs = Arrays.stream(ys).limit(N - 3).toArray();
        xs = Arrays.stream(xs).map(i -> i == N - 3 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N - 2 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N - 1 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 1 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 2 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 3 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 4 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 5 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 6 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 7 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 8 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 9 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 10 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 11 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 12 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 13 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 14 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 15 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 16 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 17 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 18 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 19 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 20 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 21 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 22 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 23 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 24 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 25 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 26 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 27 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 28 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 29 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 30 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 31 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 32 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 33 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 34 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 35 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 36 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 37 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 38 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 39 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 40 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 41 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 42 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 43 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 44 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 45 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 46 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 47 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 48 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 49 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 50 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 51 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 52 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 53 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 54 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 55 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 56 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 57 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 58 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 59 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 60 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 61 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 62 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 63 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 64 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 65 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 66 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 67 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 68 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 69 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 70 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 71 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 72 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 73 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 74 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 75 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 76 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 77 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 78 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 79 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 80 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 81 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 82 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 83 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 84 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 85 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 86 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 87 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 88 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 89 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 90 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 91 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 92 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 93 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 94 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 95 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 96 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 97 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 98 ? X : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 99 ? X + 1 : i).toArray();
        xs = Arrays.stream(xs).map(i -> i == N + 100 ? X - 1 : i).toArray();
        xs = Arrays.stream(xs).map(i ->