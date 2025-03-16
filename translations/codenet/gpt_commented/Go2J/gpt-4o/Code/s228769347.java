import java.io.*;
import java.util.*;

public class Main {
    // Method to read the next integer from the input.
    private static int getNextInt(Scanner scanner) {
        return scanner.nextInt(); // Read and return the next integer.
    }

    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in; // Default input is standard input.
        OutputStream outputStream = System.out; // Default output is standard output.

        // Check for command-line arguments to read from a file and write to a file.
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]); // Open the input file if provided.
            if (args.length > 1) {
                outputStream = new FileOutputStream(args[1]); // Create the output file if provided.
            }
        }

        Scanner scanner = new Scanner(inputStream); // Initialize the scanner for input.
        PrintWriter writer = new PrintWriter(outputStream); // Create a writer for output.

        int n = getNextInt(scanner); // Read the number of integers.
        int[] ll = new int[n]; // Create an array to hold the integers.

        // Read n integers from the input.
        for (int i = 0; i < n; i++) {
            ll[i] = getNextInt(scanner); // Populate the array with integers.
        }

        Arrays.sort(ll); // Sort the array of integers.

        int ans = 0; // Initialize the answer counter.
        // Iterate through pairs of integers to find valid triplets.
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1; // Start searching for the third element after the second element.
                int r = n; // Set the right boundary for binary search.
                // Perform binary search to find the count of valid third elements.
                while (l < r) {
                    int m = (l + r) / 2; // Calculate the middle index.
                    if (ll[m] < ll[i] + ll[j]) { // Check if the sum of the first two is greater than the middle element.
                        l = m + 1; // Move the left boundary up.
                    } else {
                        r = m; // Move the right boundary down.
                    }
                }
                // Count the number of valid third elements.
                ans += l - (j + 1); // Update the answer with the count of valid triplets.
            }
        }
        writer.println(ans); // Print the result to the output.

        writer.flush(); // Flush the writer to ensure all output is written.
        scanner.close(); // Close the scanner.
    }
}

// <END-OF-CODE>
