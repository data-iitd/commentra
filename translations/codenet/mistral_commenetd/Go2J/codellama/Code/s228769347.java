
// Package main is the entry point of the program
package main

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

    // Function to initialize a new scanner for reading input
    public static BufferedReader getScanner(File file) throws IOException {
        BufferedReader scanner = new BufferedReader(new FileReader(file));
        scanner.readLine();
        return scanner;
    }

    // Function to read the next word as a string
    public static String getNextString(BufferedReader scanner) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine());
        return tokenizer.nextToken();
    }

    // Function to read the next integer from the input
    public static int getNextInt(BufferedReader scanner) throws IOException {
        return Integer.parseInt(getNextString(scanner));
    }

    // Function to read the next long from the input
    public static long getNextLong(BufferedReader scanner) throws IOException {
        return Long.parseLong(getNextString(scanner));
    }

    // Function to read the next double from the input
    public static double getNextDouble(BufferedReader scanner) throws IOException {
        return Double.parseDouble(getNextString(scanner));
    }

    // Main function to solve the problem
    public static void main(String[] args) throws IOException {
        // Initializing standard input and output file pointers
        File fp = new File("input.txt");
        File wfp = new File("output.txt");

        // If input file and output file are provided as command line arguments
        if (args.length > 0) {
            // Open the input file
            fp = new File(args[0]);

            // If output file is provided, create it
            if (args.length > 1) {
                wfp = new File(args[1]);
            }
        }

        // Initialize a new scanner for reading input
        BufferedReader scanner = getScanner(fp);
        BufferedWriter writer = new BufferedWriter(new FileWriter(wfp));

        // Read the number of elements in the array
        int n = getNextInt(scanner);

        // Initialize a slice of length n to store the elements
        int[] ll = new int[n];

        // Read the elements of the array
        for (int i = 0; i < n; i++) {
            ll[i] = getNextInt(scanner);
        }

        // Sort the slice in ascending order
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
                    int m = (l + r) >> 1;
                    if (ll[m] < ll[i] + ll[j]) {
                        l = m + 1;
                        continue;
                    }
                    r = m;
                }

                // Update the answer variable
                ans += l - (j + 1);
            }
        }

        // Write the answer to the output file
        writer.write(String.valueOf(ans));
        writer.newLine();

        // Flush the writer buffer
        writer.flush();
    }
}

// 