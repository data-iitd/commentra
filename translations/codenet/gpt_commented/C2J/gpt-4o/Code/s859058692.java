import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables to store the sum, current number, count of numbers, and min/max values
        long sum = 0; // To hold the sum of all numbers
        int m, n, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE; // m: current number, n: total count of numbers

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the total number of integers to be processed
        n = scanner.nextInt();

        // Loop through each number to read and process
        for (int i = 0; i < n; i++) {
            // Read the current number
            m = scanner.nextInt();

            // Add the current number to the sum
            sum += m;

            // Update min if the current number is less than the current min
            if (min > m) {
                min = m; // Update min
            }

            // Update max if the current number is greater than the current max
            if (max < m) {
                max = m; // Update max
            }
        }

        // Print the minimum, maximum, and sum of the numbers
        System.out.printf("%d %d %d\n", min, max, sum);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
