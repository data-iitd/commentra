// Importing required packages
import java.io.*;
import java.util.*;

public class Main {
    // Function to read the next integer from the input
    private static int getNextInt(Scanner scanner) {
        return scanner.nextInt();
    }

    // Main function to solve the problem
    public static void main(String[] args) throws IOException {
        // Initializing standard input and output file pointers
        InputStream inputStream = System.in;
        PrintWriter writer = new PrintWriter(System.out);

        // If input file and output file are provided as command line arguments
        if (args.length > 0) {
            // Open the input file
            inputStream = new FileInputStream(args[0]);

            // If output file is provided, create it
            if (args.length > 1) {
                writer = new PrintWriter(new FileOutputStream(args[1]));
            }
        }

        // Initialize a new scanner for reading input
        Scanner scanner = new Scanner(inputStream);

        // Read the number of elements in the array
        int n = getNextInt(scanner);

        // Initialize a list to store the elements
        int[] ll = new int[n];

        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            ll[i] = getNextInt(scanner);
        }

        // Sort the array in ascending order
        Arrays.sort(ll);

        // Initialize the answer variable to 0
        int ans = 0;

        // Iterate through all possible pairs of elements
        for (int i = 0; i < n - 2; i++) {
            // Iterate through all possible right pointers
            for (int j = i + 1; j < n - 1; j++) {
                // Initialize the left and right pointers for binary search
                int l = j + 1;
                int r = n;

                // Binary search to find the index of the element greater than the sum of the current pair
                while (l < r) {
                    int m = (l + r) / 2;
                    if (ll[m] < ll[i] + ll[j]) {
                        l = m + 1;
                    } else {
                        r = m;
                    }
                }

                // Update the answer variable
                ans += l - (j + 1);
            }
        }

        // Write the answer to the output file
        writer.println(ans);

        // Flush the writer buffer
        writer.flush();
        writer.close();
        scanner.close();
    }
}

// <END-OF-CODE>
