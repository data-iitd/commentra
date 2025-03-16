public class ATM {
    public static void main(String[] args) {
        // Disable synchronization with C I/O for faster input/output
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        scanner.useDelimiter("\\s*");

        // Initialize a vector to hold the denominations of money
        java.util.ArrayList<Integer> m = new java.util.ArrayList<>();
        m.add(10);   // Add 10
        m.add(50);   // Add 50
        m.add(100);  // Add 100
        m.add(500);  // Add 500

        boolean first = true; // Flag to handle formatting of output
        // Read money input until EOF or invalid input
        while (scanner.hasNextInt()) {
            int money = scanner.nextInt();
            if (money == 0) break; // Exit loop if money is 0

            // Print a newline before the output of subsequent transactions
            if (!first)
                System.out.println();

            first = false; // Set the flag to false after the first input
            int sum = 0; // Initialize sum to calculate total value of coins
            int[] num = new int[4]; // Array to hold the number of each denomination

            // Read the number of coins for each denomination and calculate the total sum
            for (int i = 0; i < 4; ++i) {
                num[i] = scanner.nextInt(); // Input the number of coins for the current denomination
                sum += num[i] * m.get(i); // Update the total sum
            }

            // Calculate the change to be returned
            int change = sum - money;

            // Calculate how many coins of each denomination to return as change
            for (int i = 3; i >= 0; --i) {
                if (change / m.get(i) > 0) { // Check if the current denomination can be used for change
                    num[i] = num[i] - change / m.get(i); // Reduce the number of coins of this denomination
                    change %= m.get(i); // Update the remaining change to be returned
                }
            }

            // Output the remaining coins of each denomination that are greater than zero
            for (int i = 0; i < 4; ++i)
                if (num[i] > 0) // Only print denominations that still have coins left
                    System.out.println(m.get(i) + " " + num[i]); // Print denomination and count
        }
    }
}
