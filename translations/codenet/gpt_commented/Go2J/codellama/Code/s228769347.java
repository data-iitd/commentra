
package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // getScanner initializes a new scanner for reading from the provided file pointer.
    public static BufferedReader getScanner(File fp) throws IOException {
        BufferedReader scanner = new BufferedReader(new FileReader(fp));
        return scanner;
    }

    // getNextString reads the next word from the scanner and returns it as a string.
    public static String getNextString(BufferedReader scanner) throws IOException {
        String next = scanner.readLine();
        return next;
    }

    // getNextInt converts the next word from the scanner to an integer and returns it.
    public static int getNextInt(BufferedReader scanner) throws IOException {
        int i = Integer.parseInt(getNextString(scanner)); // Convert the string to an int.
        return i; // Return the integer.
    }

    // getNextInt64 converts the next word from the scanner to an int64 and returns it.
    public static long getNextInt64(BufferedReader scanner) throws IOException {
        long i = Long.parseLong(getNextString(scanner)); // Convert the string to an int64.
        return i; // Return the int64.
    }

    // getNextUint64 converts the next word from the scanner to a uint64 and returns it.
    public static long getNextUint64(BufferedReader scanner) throws IOException {
        long i = Long.parseLong(getNextString(scanner)); // Convert the string to a uint64.
        return i; // Return the uint64.
    }

    // getNextFloat64 converts the next word from the scanner to a float64 and returns it.
    public static double getNextFloat64(BufferedReader scanner) throws IOException {
        double i = Double.parseDouble(getNextString(scanner)); // Convert the string to a float64.
        return i; // Return the float64.
    }

    public static void main(String[] args) throws IOException {
        BufferedReader fp = new BufferedReader(new InputStreamReader(System.in)); // Default input is standard input.
        BufferedWriter wfp = new BufferedWriter(new OutputStreamWriter(System.out)); // Default output is standard output.

        // Check for command-line arguments to read from a file and write to a file.
        if (args.length > 0) {
            fp = getScanner(new File(args[0])); // Open the input file if provided.
            if (args.length > 1) {
                wfp = new BufferedWriter(new FileWriter(args[1])); // Create the output file if provided.
            }
        }

        BufferedReader scanner = getScanner(fp); // Initialize the scanner for input.
        BufferedWriter writer = wfp; // Create a buffered writer for output.

        int n = getNextInt(scanner); // Read the number of integers.
        int[] ll = new int[n]; // Create a slice to hold the integers.

        // Read n integers from the input.
        for (int i = 0; i < n; i++) {
            ll[i] = getNextInt(scanner); // Populate the slice with integers.
        }

        Arrays.sort(ll); // Sort the slice of integers.

        int ans = 0; // Initialize the answer counter.
        // Iterate through pairs of integers to find valid triplets.
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1; // Start searching for the third element after the second element.
                int r = n; // Set the right boundary for binary search.
                // Perform binary search to find the count of valid third elements.
                while (l < r) {
                    int m = (l + r) >> 1; // Calculate the middle index.
                    if (ll[m] < ll[i] + ll[j]) { // Check if the sum of the first two is greater than the middle element.
                        l = m + 1; // Move the left boundary up.
                        continue;
                    }
                    r = m; // Move the right boundary down.
                }
                // Count the number of valid third elements.
                ans += l - (j + 1); // Update the answer with the count of valid triplets.
            }
        }
        writer.write(String.valueOf(ans)); // Print the result to the output.
        writer.flush(); // Flush the buffered writer to ensure all output is written.
    }
}

