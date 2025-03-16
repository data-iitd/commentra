import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        long sum = 0; // Declare and initialize the sum variable
        int m, n, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE; // Declare variables for the number of inputs, current input, min, and max
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        n = scanner.nextInt(); // Read the number of inputs

        // Loop through each input
        for (int i = 0; i < n; i++) {
            m = scanner.nextInt(); // Read the current input
            sum += m; // Update the sum with the current input

            // Update the min value if the current input is smaller
            if (min > m) {
                min = m;
            }

            // Update the max value if the current input is larger
            if (max < m) {
                max = m;
            }
        }

        // Output the minimum, maximum, and sum of the inputs
        System.out.printf("%d %d %d\n", min, max, sum);
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
