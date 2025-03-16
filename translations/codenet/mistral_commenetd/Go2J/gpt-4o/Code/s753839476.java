import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        IO io = new IO();
        
        // Read input values
        int n = io.scanInt();
        double t = io.scanFloat64();
        double a = io.scanFloat64();

        // Initialize variables for heights and minimum difference
        double[] heights = io.scanFloat64s(n);
        double minDiff = absDiff(t - heights[0] * 0.006, a);
        int minIdx = 0;

        // Iterate through the remaining heights and find the minimum difference
        for (int i = 1; i < heights.length; i++) {
            // Calculate the difference between the target and the height
            double diff = absDiff(t - heights[i] * 0.006, a);

            // Update minimum difference and index if the current difference is smaller
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }

        // Print the result
        System.out.println(minIdx + 1);
    }

    // Calculate absolute difference between two double numbers
    public static double absDiff(double n1, double n2) {
        return Math.abs(n1 - n2);
    }

    // IO class for handling input and output
    static class IO {
        private final Scanner scanner;

        public IO() {
            this.scanner = new Scanner(System.in);
        }

        // Read a single integer from the scanner
        public int scanInt() {
            return Integer.parseInt(scanString());
        }

        // Read a single float64 from the scanner
        public double scanFloat64() {
            return Double.parseDouble(scanString());
        }

        // Read a slice of float64 from the scanner
        public double[] scanFloat64s(int n) {
            double[] floats = new double[n];
            for (int i = 0; i < n; i++) {
                floats[i] = scanFloat64();
            }
            return floats;
        }

        // Read a single string from the scanner
        public String scanString() {
            return scanner.next();
        }
    }
}
// <END-OF-CODE>
