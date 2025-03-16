import java.util.Scanner; // Import the Scanner class for input operations.

public class Main { // Define the main class.
    public static void main(String[] args) { // The main method where the execution of the program begins.
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for reading input.
        int n = scanner.nextInt(); // Read the value of n from the standard input.
        
        long[] a = new long[n + 1]; // Declare an array to store the input values.
        long[] pre = new long[n + 1]; // Declare an array to store the prefix sums.
        long[] last = new long[n + 1]; // Declare an array to store the suffix sums.

        for (int i = 1; i <= n; i++) { // Loop to read n integers into the array a.
            a[i] = scanner.nextLong(); // Read the i-th integer and store it in a[i].
        }

        long sumpre = 0, sumlast = 0; // Declare variables to store the cumulative sums of prefix and suffix.
        for (int i = 1; i < n; i++) { // Loop to calculate the prefix sums.
            sumpre += a[i]; // Add the current element to the cumulative sum.
            pre[i] = sumpre; // Store the cumulative sum in the pre array.
        }

        for (int i = n; i > 1; i--) { // Loop to calculate the suffix sums.
            sumlast += a[i]; // Add the current element to the cumulative sum.
            last[i] = sumlast; // Store the cumulative sum in the last array.
        }

        long d = (1L << 60); // Declare a variable to store the minimum difference and initialize it to a large number.
        for (int i = 1; i < n; i++) { // Loop to find the minimum absolute difference between prefix and suffix sums.
            d = Math.min(d, Math.abs(pre[i] - last[i + 1])); // Update the minimum difference if a smaller one is found.
        }

        System.out.println(d); // Print the minimum difference found.
        scanner.close(); // Close the scanner to free resources.
    }
} // End of the Main class
// <END-OF-CODE>
