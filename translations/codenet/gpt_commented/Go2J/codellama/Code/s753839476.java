
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        // Initialize input/output handling
        IO io = new IO();
        // Read the number of heights, target temperature, and actual temperature
        int n = io.scanInt();
        double t = io.scanDouble();
        double a = io.scanDouble();
        // Read the heights as a double array
        double[] heights = io.scanDoubleArray(n);

        // Initialize minimum difference and index for tracking the closest height
        double minDiff = Math.abs(t - heights[0] * 0.006 - a);
        int minIdx = 0;

        // Iterate through the heights to find the one with the minimum temperature difference
        for (int i = 1; i < heights.length; i++) {
            double h = heights[i];
            double diff = Math.abs(t - h * 0.006 - a);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }

        // Output the 1-based index of the closest height
        io.println(minIdx + 1);
    }

    static class IO {
        BufferedReader reader;
        PrintWriter writer;

        IO() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
        }

        String scanLine() throws IOException {
            return reader.readLine();
        }

        int scanInt() throws IOException {
            return Integer.parseInt(scanLine());
        }

        double scanDouble() throws IOException {
            return Double.parseDouble(scanLine());
        }

        double[] scanDoubleArray(int n) throws IOException {
            double[] array = new double[n];
            for (int i = 0; i < n; i++) {
                array[i] = scanDouble();
            }
            return array;
        }

        void println(Object object) {
            writer.println(object);
        }
    }
}

