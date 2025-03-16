
package main;

import java.io.*;
import java.util.*;

public class Main {

    // Function to create a new bufio.Scanner from a file pointer
    public static Scanner getScanner(File fp) {
        Scanner scanner = new Scanner(fp);
        scanner.useDelimiter("[^\\p{L}]+");
        return scanner;
    }

    // Function to read the next string from the scanner
    public static String getNextString(Scanner scanner) {
        scanner.findInLine("[^\\p{L}]+");
        return scanner.next();
    }

    // Function to read the next integer from the scanner
    public static int getNextInt(Scanner scanner) {
        return Integer.parseInt(scanner.findInLine("[^\\p{L}]+"));
    }

    // Function to read the next int64 from the scanner
    public static long getNextInt64(Scanner scanner) {
        return Long.parseLong(scanner.findInLine("[^\\p{L}]+"));
    }

    // Main function
    public static void main(String[] args) {
        // Open the standard input as a file
        File fp = new File("input.txt");
        // If there is an argument, open the file with that name instead
        if (args.length > 0) {
            fp = new File(args[0]);
        }

        // Create a new bufio.Scanner from the file pointer
        Scanner scanner = getScanner(fp);

        // Create a new bufio.Writer for output
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read the first integer from the input
        int n = getNextInt(scanner);

        // Initialize an array 'aa' of size 'n+2'
        int[] aa = new int[n+2];
        // Initialize a variable'sum' to store the sum of absolute differences between consecutive elements
        int sum = 0;

        // Iterate through the array 'aa' and calculate the sum of absolute differences between consecutive elements
        for (int i = 0; i < n; i++) {
            // Read the next integer from the scanner and store it in 'aa[i+1]'
            aa[i+1] = getNextInt(scanner);
            // Calculate the absolute difference between the current and previous elements and add it to the sum
            sum += Math.abs(aa[i+1] - aa[i]);
        }
        // Calculate the absolute difference between the last two elements and add it to the sum
        sum += Math.abs(aa[n+1] - aa[n]);

        // Iterate through the array 'aa' and print the answer for each subarray
        for (int i = 1; i < n+1; i++) {
            // Calculate the answer for the subarray from 'aa[i]' to 'aa[i+1]'
            int ans = sum - Math.abs(aa[i+1]-aa[i]) - Math.abs(aa[i]-aa[i-1]) + Math.abs(aa[i+1]-aa[i-1]);
            // Write the answer to the output writer
            writer.write(ans + "\n");
        }

        // Flush the buffer to write all the data to the output
        writer.flush();
    }
}

