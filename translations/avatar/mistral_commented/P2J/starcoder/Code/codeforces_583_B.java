// Define the main function
public static void main(String[] args) {
    // Read the number of test cases
    int n = Integer.parseInt(args[0]);

    // Read the array of integers
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = Integer.parseInt(args[i + 1]);
    }

    // Initialize variables
    int currentLevel = 0;
    int counter = 0;
    int counterTurns = -1;

    // Main loop
    while (counter < n) {
        // Increment turns counter
        counterTurns++;

        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // If current index is valid and its value is less than or equal to current level
            if (a[i]!= -1 && a[i] <= currentLevel) {
                // Increment counter and mark the index as visited
                counter++;
                a[i] = -1;
            }
        }

        // Reverse the array
        reverse(a);
    }

    // Print the result
    System.out.println(counterTurns);
}

// Reverse the array
public static void reverse(int[] a) {
    int start = 0;
    int end = a.length - 1;
    while (start < end) {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        start++;
        end--;
    }
}

// 