import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        IO io = new IO(); // Initialize IO
        int n = io.scanInt(); // Read value for n
        double t = io.scanFloat64(); // Read value for t
        double a = io.scanFloat64(); // Read value for a
        double[] heights = io.scanFloat64s(n); // Read a list of heights

        double minDiff = absDiff(t - heights[0] * 0.006, a); // Calculate the initial minimum difference
        int minIdx = 0; // Initialize the index of the minimum difference
        for (int i = 1; i < n; i++) { // Iterate through the heights starting from the second element
            double diff = absDiff(t - heights[i] * 0.006, a); // Calculate the difference for the current height
            if (diff < minDiff) { // Update the minimum difference and index if a smaller difference is found
                minDiff = diff;
                minIdx = i;
            }
        }
        System.out.println(minIdx + 1); // Print the index (plus one for 1-based indexing)
    }

    // AbsDiff computes the absolute difference between two double numbers
    public static double absDiff(double n1, double n2) {
        return Math.abs(n1 - n2);
    }

    // IO class for input/output operations
    static class IO {
        private BufferedReader reader;
        private PrintWriter writer;
        private StringTokenizer tokenizer;

        public IO() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
            tokenizer = new StringTokenizer("");
        }

        // Scan the next integer from the input
        public int scanInt() throws IOException {
            return Integer.parseInt(scanString());
        }

        // Scan the next double from the input
        public double scanFloat64() throws IOException {
            return Double.parseDouble(scanString());
        }

        // Scan n doubles from the input
        public double[] scanFloat64s(int n) throws IOException {
            double[] floats = new double[n];
            for (int i = 0; i < n; i++) {
                floats[i] = scanFloat64();
            }
            return floats;
        }

        // Scan the next string from the input
        private String scanString() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }
    }
}
// <END-OF-CODE>
