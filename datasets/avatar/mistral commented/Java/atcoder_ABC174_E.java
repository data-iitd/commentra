import java.io.BufferedReader;  // Import BufferedReader for reading input
import java.io.IOException;     // Import IOException for handling input/output errors
import java.io.InputStream;     // Import InputStream for reading input
import java.io.OutputStream;    // Import OutputStream for writing output
import java.io.PrintWriter;     // Import PrintWriter for writing output
import java.util.StringTokenizer; // Import StringTokenizer for tokenizing input

public class Main {
    // Main method to start the program
    public static void main ( String [ ] args ) {
        InputStream inputStream = System.in;  // Initialize input stream from standard input
        OutputStream outputStream = System.out; // Initialize output stream to standard output
        InputReader in = new InputReader(inputStream); // Create an InputReader object
        PrintWriter out = new PrintWriter(outputStream); // Create a PrintWriter object
        Solution sol = new Solution(); // Create a Solution object
        sol.solve(in, out); // Call the solve method of Solution object
        out.close(); // Close the PrintWriter object
    }

    // Private nested class for the solution logic
    private static class Solution {
        // Method to solve the problem using the given input and output objects
        private void solve ( InputReader in , PrintWriter out ) {
            int n = in.nextInt(); // Read the number of logs
            int k = in.nextInt(); // Read the number of days

            // Initialize the minimum and maximum possible days
            int min = 1, max = (int) 1e9 + 1000;

            // Binary search to find the minimum day such that the number of days needed to cut the logs is greater than or equal to k
            while (min < max) {
                int mid = (min + max) / 2; // Calculate the middle day
                if (nei(mid, logsLength, k)) // If the number of days needed to cut the logs is greater than or equal to k
                    max = mid; // Narrow down the search space to the left
                else
                    min = mid + 1; // Narrow down the search space to the right
            }

            // Print the minimum day as the output
            out.println(min);
        }

        // Method to check if the number of days needed to cut the logs of given length is greater than or equal to k
        private boolean nei ( int mid , int [ ] logsLength , int k ) {
            int daysNeeded = 0; // Initialize the days needed to zero

            // Iterate through all the logs and calculate the days needed to cut them
            for (int log : logsLength) {
                daysNeeded += (log + mid - 1) / mid; // Calculate the days needed to cut the current log
                k -= daysNeeded; // Subtract the days needed from the remaining days
                if (k < 0) // If the remaining days are not sufficient to cut all the logs
                    return false; // Return false to indicate that the middle day is not the answer
            }

            // If all the logs have been cut, return true to indicate that the middle day is the answer
            return true;
        }
    }

    // Private nested static class for reading input
    private static class InputReader {
        private BufferedReader reader; // Initialize BufferedReader object
        private StringTokenizer tokenizer; // Initialize StringTokenizer object

        // Constructor to initialize the InputReader object with the given input stream
        private InputReader ( InputStream stream ) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768); // Initialize BufferedReader with the given input stream
            tokenizer = null; // Initialize StringTokenizer to null
        }

        // Method to read a string token
        private String next () {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String line = reader.readLine(); // Read a line from the input
                    if (line == null) throw new RuntimeException(); // If the end of the input is reached, throw an exception
                    tokenizer = new StringTokenizer(line); // Initialize StringTokenizer with the line
                } catch (IOException e) {
                    throw new RuntimeException(e); // If an input/output error occurs, throw a runtime exception
                }
            }
            return tokenizer.nextToken(); // Return the next token
        }

        // Method to read an integer
        private int nextInt () {
            return Integer.parseInt(next()); // Parse the next token as an integer
        }

        // Method to read an array of integers
        private int [ ] readArray ( int n ) {
            int [ ] a = new int [ n ]; // Initialize an array of size n
            for (int i = 0; i < n; ++i) // Iterate through all the elements of the array
                a [ i ] = nextInt(); // Read an integer as the next element
            return a; // Return the array
        }
    }
}
