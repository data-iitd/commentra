import java.io.BufferedReader; // Importing BufferedReader for efficient input reading
import java.io.IOException; // Importing IOException for handling input/output exceptions
import java.io.InputStream; // Importing InputStream for reading from the standard input
import java.io.InputStreamReader; // Importing InputStreamReader to convert InputStream to Reader
import java.io.OutputStream; // Importing OutputStream for writing to the standard output
import java.io.PrintWriter; // Importing PrintWriter for efficient output writing
import java.util.StringTokenizer; // Importing StringTokenizer for tokenizing input strings

public class Main { // Main class is the entry point of the program
    public static void main(String[] args) { // Main method is the entry point of the program
        InputStream inputStream = System.in; // Get the input stream from the system
        OutputStream outputStream = System.out; // Get the output stream from the system
        InputReader in = new InputReader(inputStream); // Create an InputReader object to read input
        PrintWriter out = new PrintWriter(outputStream); // Create a PrintWriter object to write output
        Solution sol = new Solution(); // Create a Solution object to solve the problem
        sol.solve(in, out); // Call the solve method to process the input and produce output
        out.close(); // Close the PrintWriter to flush the output buffer
    }

    private static class Solution { // Solution class contains the logic for solving the problem
        private void solve(InputReader in, PrintWriter out) { // solve method reads input, processes it, and writes the output
            int n = in.nextInt(); // Read the number of logs
            int k = in.nextInt(); // Read the number of cuts allowed
            int[] logsLength = in.readArray(n); // Read the lengths of the logs
            int min = 1, max = (int) 1e9 + 1000; // Initialize the binary search range
            while (min < max) { // Perform binary search
                int mid = (min + max) / 2; // Calculate the middle value
                if (nei(mid, logsLength, k)) { // Check if the current mid can be used to cut all logs
                    max = mid; // Adjust the max value to search in the lower half
                } else {
                    min = mid + 1; // Adjust the min value to search in the upper half
                }
            }
            out.println(min); // Print the result
        }

        private boolean nei(int mid, int[] logsLength, int k) { // nei method checks if the current mid can be used to cut all logs
            for (int log : logsLength) { // Iterate through each log
                k -= (log + mid - 1) / mid - 1; // Calculate the number of cuts needed for the current log
                if (k < 0) { // If k is negative, it means we cannot make the required cuts
                    return false; // Return false as the current mid cannot be used
                }
            }
            return true; // Return true if all logs can be cut with the given number of k
        }
    }

    private static class InputReader { // InputReader class helps in reading inputs efficiently
        private BufferedReader reader; // BufferedReader for efficient input reading
        private StringTokenizer tokenizer; // StringTokenizer for tokenizing input strings

        private InputReader(InputStream stream) { // Constructor to initialize the InputReader
            reader = new BufferedReader(new InputStreamReader(stream), 32768); // Initialize the BufferedReader
            tokenizer = null; // Initialize the tokenizer as null
        }

        private String next() { // Method to read the next token
            while (tokenizer == null || !tokenizer.hasMoreTokens()) { // Check if there are more tokens
                try {
                    tokenizer = new StringTokenizer(reader.readLine()); // Read the next line and tokenize it
                } catch (IOException e) {
                    throw new RuntimeException(e); // Throw a RuntimeException if an IOException occurs
                }
            }
            return tokenizer.nextToken(); // Return the next token
        }

        private int nextInt() { // Method to read the next integer
            return Integer.parseInt(next()); // Parse the next token as an integer
        }

        private int[] readArray(int n) { // Method to read an array of integers
            int[] a = new int[n]; // Initialize the array
            for (int i = 0; i < n; ++i) { // Iterate through the array
                a[i] = nextInt(); // Read the next integer and store it in the array
            }
            return a; // Return the array
        }
    }
}
