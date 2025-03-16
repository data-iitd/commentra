package main;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Initialize file pointers for input and output.
        Scanner scanner = new Scanner(System.in);
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Check for command line arguments to open input and output files.
        if (args.length > 0) {
            scanner = new Scanner(new File(args[0]));
            if (args.length > 1) {
                writer = new BufferedWriter(new FileWriter(args[1]));
            }
        }

        // Read the number of integers to process.
        int n = scanner.nextInt();

        // Initialize the answer as "second" and check for odd integers.
        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt(); // Read the next integer.
            if (a % 2 == 1) { // Check if the integer is odd.
                ans = "first"; // If odd, set answer to "first".
                break; // Exit the loop early if an odd integer is found.
            }
        }

        // Write the result to the output.
        writer.write(ans);
        writer.newLine();
        writer.flush(); // Ensure all buffered data is written to the output.
    }
}

