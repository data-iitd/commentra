
import java.io.BufferedReader; // Buffered reader for reading input
import java.io.IOException; // Exception for I/O errors
import java.io.InputStreamReader; // Input stream reader for reading from console
import java.io.PrintWriter; // Print writer for writing output
import java.util.Arrays; // Utility class for array manipulation

public class Main {

    // Method to check if a given string represents a valid solution
    public static boolean isSolution(int columnsCount, String x) {
        boolean[] allXs = new boolean[columnsCount]; // Initialize an array to keep track of the presence of 'X' in each column
        Arrays.fill(allXs, true); // Set all columns to have 'X' initially

        // Iterate through the given string and mark the corresponding columns as not having 'X'
        for (int i = 0; i < 12; i++) {
            if (x.charAt(i) != 'X') {
                allXs[i % columnsCount] = false; // Update the corresponding column
            }
        }

        // Check if there is any column having 'X'
        for (int i = 0; i < columnsCount; i++) {
            if (allXs[i]) { // If 'X' is present in this column
                return true; // Return true as this is a valid solution
            }
        }

        return false; // If no column has 'X', then this is not a valid solution
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Read input from console
        PrintWriter pw = new PrintWriter(System.out); // Write output to console
        int t = Integer.parseInt(br.readLine()); // Read the number of test cases

        for (int i = 0; i < t; i++) { // Iterate through each test case
            int possibleSolutions = 0; // Initialize the counter for the number of valid solutions
            StringBuilder solutions = new StringBuilder(); // Initialize a string builder to store the valid solutions

            String s = br.readLine(); // Read the given string

            // Check if the given string represents a valid solution
            if (isSolution(12, s)) {
                solutions.append(" 1x12"); // Add the solution to the string builder
                possibleSolutions++; // Increment the counter
            }

            if (isSolution(6, s)) {
                solutions.append(" 2x6");
                possibleSolutions++;
            }

            if (isSolution(4, s)) {
                solutions.append(" 3x4");
                possibleSolutions++;
            }

            if (isSolution(3, s)) {
                solutions.append(" 4x3");
                possibleSolutions++;
            }

            if (isSolution(2, s)) {
                solutions.append(" 6x2");
                possibleSolutions++;
            }

            if (isSolution(1, s)) {
                solutions.append(" 12x1");
                possibleSolutions++;
            }

            // Write the output
            pw.print(possibleSolutions + " "); // Write the number of valid solutions
            pw.println(solutions); // Write the valid solutions
        }

        pw.flush(); // Flush the print writer buffer
        pw.close(); // Close the print writer
    }
}

These comments should provide a clear understanding of the code logic for each block.