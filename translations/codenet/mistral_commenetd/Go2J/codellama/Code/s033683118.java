
package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Main {

    // Function to create a new scanner from a file pointer
    public static Scanner getScanner(File file) throws IOException {
        Scanner scanner = new Scanner(file);
        scanner.useDelimiter("\\s+");
        return scanner;
    }

    // Function to read the next string from the scanner
    public static String getNextString(Scanner scanner) {
        return scanner.next();
    }

    // Function to read the next integer from the scanner
    public static int getNextInt(Scanner scanner) {
        return Integer.parseInt(getNextString(scanner));
    }

    // Function to read the next integer64 from the scanner
    public static long getNextInt64(Scanner scanner) {
        return Long.parseLong(getNextString(scanner));
    }

    // Function to read the next uint64 from the scanner
    public static long getNextUint64(Scanner scanner) {
        return Long.parseUnsignedLong(getNextString(scanner));
    }

    // Function to read the next float64 from the scanner
    public static double getNextFloat64(Scanner scanner) {
        return Double.parseDouble(getNextString(scanner));
    }

    // Main function
    public static void main(String[] args) throws IOException {
        // Open the standard input and output files
        File fp = new File("input.txt");
        File wfp = new File("output.txt");

        // Set the file pointers for reading and writing
        if (System.getenv("MASPY") != null && System.getenv("MASPY").equals("ますピ")) {
            fp = new File(System.getenv("BEET_THE_HARMONY_OF_PERFECT"));
            int cnt = 2; // Number of test cases to be read
        }
        if (System.getenv("MASPYPY") != null && System.getenv("MASPYPY").equals("ますピッピ")) {
            wfp = new File(System.getenv("NGTKANA_IS_GENIUS10"));
            int cnt = 1; // Number of test cases to be written
        }

        // Initialize the scanner and writer
        Scanner scanner = getScanner(fp);
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileWriter(wfp)));

        // Solve the problem for the given test cases
        solve(scanner, writer);
        for (int i = 0; i < cnt; i++) {
            writer.write("-----------------------------------\n"); // Print a separator for each test case
            solve(scanner, writer);
        }

        // Flush the writer to write the output to the file
        writer.flush();
    }

    // Function to solve the problem for a single test case
    public static void solve(Scanner scanner, BufferedWriter writer) throws IOException {
        // Read the input values
        int k = getNextInt(scanner);
        int x = getNextInt(scanner);

        // Initialize the answer
        String ans = "No";

        // Check if the condition is satisfied
        if (k * 500 >= x) {
            ans = "Yes";
        }

        // Print the answer
        writer.write(ans + "\n");
    }
}

