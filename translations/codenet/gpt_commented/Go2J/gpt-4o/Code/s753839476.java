import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize input/output handling
        IO io = new IO();
        
        // Read the number of heights, target temperature, and actual temperature
        int n = io.scanInt();
        double t = io.scanFloat64();
        double a = io.scanFloat64();
        
        // Read the heights as a list of doubles
        double[] heights = io.scanFloat64s(n);

        // Initialize minimum difference and index for tracking the closest height
        double minDiff = absDiff(t - heights[0] * 0.006, a);
        int minIdx = 0;

        // Iterate through the heights to find the one with the minimum temperature difference
        for (int i = 1; i < n; i++) {
            double diff = absDiff(t - heights[i] * 0.006, a);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i; // Update the index of the closest height
            }
        }

        // Output the 1-based index of the closest height
        System.out.println(minIdx + 1);
    }

    // AbsDiff calculates the absolute difference between two double numbers
    public static double absDiff(double n1, double n2) {
        return Math.abs(n1 - n2);
    }

    // IO class for handling input and output operations
    static class IO {
        private final BufferedReader reader;
        private final PrintWriter writer;
        private StringTokenizer tokenizer;

        public IO() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
        }

        // ScanBytes scans and returns a byte array from input
        public byte[] scanBytes() throws IOException {
            return reader.readLine().getBytes();
        }

        // ScanString scans and returns a string from input
        public String scanString() throws IOException {
            return reader.readLine();
        }

        // ScanInt scans and returns an integer from input
        public int scanInt() throws IOException {
            return Integer.parseInt(scanString());
        }

        // ScanFloat64 scans and returns a double from input
        public double scanFloat64() throws IOException {
            return Double.parseDouble(scanString());
        }

        // ScanFloat64s scans and returns an array of doubles from input
        public double[] scanFloat64s(int n) throws IOException {
            double[] floats = new double[n];
            for (int i = 0; i < n; i++) {
                floats[i] = scanFloat64();
            }
            return floats;
        }

        // Println writes a line to the output
        public void println(Object... a) {
            for (Object obj : a) {
                writer.print(obj + " ");
            }
            writer.println();
            writer.flush();
        }
    }
}
// <END-OF-CODE>
