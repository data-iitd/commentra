
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
import java.util.Scanner;

public class Main {

    // getScanner initializes a new Scanner to read from a file pointer.
    // It sets the split function to ScanWords and buffers to 500001 bytes.
    public static Scanner getScanner(File file) throws IOException {
        Scanner scanner = new Scanner(file);
        scanner.useDelimiter("\\s+");
        scanner.buffer(500001);
        return scanner;
    }

    // getScanner initializes a new Scanner to read from standard input.
    // It sets the split function to ScanWords and buffers to 500001 bytes.
    public static Scanner getScanner() throws IOException {
        Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        scanner.useDelimiter("\\s+");
        scanner.buffer(500001);
        return scanner;
    }

    // getNextString reads the next token from the Scanner and returns it as a string.
    public static String getNextString(Scanner scanner) {
        scanner.next();
        return scanner.next();
    }

    // getNextInt reads the next token as a string, converts it to an integer, and returns it.
    public static int getNextInt(Scanner scanner) {
        return Integer.parseInt(getNextString(scanner));
    }

    // getNextInt64 reads the next token as a string, converts it to an int64, and returns it.
    public static long getNextInt64(Scanner scanner) {
        return Long.parseLong(getNextString(scanner));
    }

    // getNextUint64 reads the next token as a string, converts it to a uint64, and returns it.
    public static long getNextUint64(Scanner scanner) {
        return Long.parseLong(getNextString(scanner));
    }

    // getNextFloat64 reads the next token as a string, converts it to a float64, and returns it.
    public static double getNextFloat64(Scanner scanner) {
        return Double.parseDouble(getNextString(scanner));
    }

    // main function handles file input/output based on command-line arguments.
    // It reads integers from the specified file or standard input, sorts them,
    // and calculates the number of valid triplets (i, j, m) where i < j < m and ll[m] < ll[i] + ll[j].
    public static void main(String[] args) throws IOException {
        File file = new File("");
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        // Check if file paths are provided as command-line arguments.
        if (args.length > 0) {
            file = new File(args[0]);
            if (args.length > 1) {
                writer = new BufferedWriter(new FileWriter(args[1]));
            }
        }

        Scanner scanner = getScanner(file);

        // Read the number of elements.
        int n = getNextInt(scanner);
        int[] ll = new int[n];

        // Read n integers into the slice ll.
        for (int i = 0; i < n; i++) {
            ll[i] = getNextInt(scanner);
        }

        // Sort the slice ll.
        Arrays.sort(ll);

        // Initialize the answer variable.
        int ans = 0;

        // Iterate through possible triplets (i, j, m) where i < j < m.
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int l = j + 1;
                int r = n;
                while (l < r) {
                    int m = (l + r) >> 1;
                    if (ll[m] < ll[i] + ll[j]) {
                        l = m + 1;
                        continue;
                    }
                    r = m;
                }

                // Add the number of valid m's to the answer.
                ans += l - (j + 1);
            }
        }

        // Print the final answer to the standard output.
        writer.write(String.valueOf(ans));
        writer.newLine();

        // Flush the writer to ensure all data is written to the file or standard output.
        writer.flush();
    }
}

