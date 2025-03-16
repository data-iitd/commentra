
import java.io.BufferedReader; // Import BufferedReader for reading input from standard input
import java.io.IOException; // Import IOException for handling input/output errors
import java.io.InputStreamReader; // Import InputStreamReader for wrapping an input stream
import java.util.*; // Import the util package for using collections like HashMap

public class Main {
    // Main method is the entry point of the Java application
    public static void main(String[] args) {
        FastScanner input = new FastScanner(); // Create an instance of FastScanner class for reading input
        int n = input.nextInt(); // Read the number of integers from the standard input

        // Initialize an empty HashMap with Integer keys and Integer values
        HashMap<Integer, Integer> map = new HashMap<>();

        // Iterate through the given number of integers and add each integer to the HashMap with its count
        for (int i = 0; i < n; i++) {
            int val = input.nextInt(); // Read the next integer from the standard input
            map.put(val, map.getOrDefault(val, 0) + 1); // Add the integer to the HashMap with its count or 1 if it's the first occurrence
        }

        // Initialize minimum value and maximum value variables
        int max = Integer.MIN_VALUE;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            // Update the maximum value if the current entry's value is greater than the maximum value
            Integer value = entry.getValue();
            max = Math.max(max, value);
        }

        // Print the maximum value and the size of the HashMap
        System.out.println(max + " " + map.size());
    }

    // FastScanner class for reading input efficiently
    static class FastScanner {
        BufferedReader br; // BufferedReader for reading input
        StringTokenizer st; // StringTokenizer for parsing input

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in)); // Initialize BufferedReader with System.in as input source
        }

        String next() { // Read the next token from the input
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine()); // Create a new StringTokenizer with the next line from the input
                } catch (IOException e) {
                    e.printStackTrace(); // Print the error message if an I/O error occurs
                }
            }
            return st.nextToken(); // Return the next token
        }

        int nextInt() { // Read the next integer from the input
            return Integer.parseInt(next());
        }

        long nextLong() { // Read the next long integer from the input
            return Long.parseLong(next());
        }

        double nextDouble() { // Read the next double from the input
            return Double.parseDouble(next());
        }

        String nextLine() throws IOException { // Read the next line from the input
            return br.readLine();
        }
    }
}

These comments should provide a clear understanding of the code's functionality and logic.