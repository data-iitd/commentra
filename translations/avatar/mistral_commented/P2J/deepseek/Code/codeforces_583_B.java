public class Main {
    public static void main(String[] args) {
        // Read the number of test cases
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Read the array of integers
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize variables
        int currentLevel = 0;
        int counter = 0;
        int counterTurns = -1;

        // Main loop
        while (counter < a.length) {
            // Increment turns counter
            counterTurns++;

            // Iterate through the array
            for (int i = 0; i < a.length; i++) {
                // If current index is valid and its value is less than or equal to current level
                if (a[i] != -1 && a[i] <= counter) {
                    // Increment counter and mark the index as visited
                    counter++;
                    a[i] = -1;
                }
            }

            // Reverse the array
            java.util.Collections.reverse(java.util.Arrays.asList(a));
        }

        // Print the result
        System.out.println(counterTurns);
    }
}
