
package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        IO io = new IO();
        try {
            // Read input values
            int n = io.scanInt();
            double t = io.scanDouble();
            double a = io.scanDouble();

            // Initialize variables for heights and minimum difference
            double[] heights = io.scanDoubles(n);
            double minDiff = Math.abs(t - heights[0] * 0.006);
            int minIdx = 0;

            // Iterate through the remaining heights and find the minimum difference
            for (int i = 1; i < n; i++) {
                // Calculate the difference between the target and the height
                double diff = Math.abs(t - heights[i] * 0.006);

                // Update minimum difference and index if the current difference is smaller
                if (diff < minDiff) {
                    minDiff = diff;
                    minIdx = i;
                }
            }

            // Print the result
            io.println(minIdx + 1);
        } finally {
            io.close();
        }
    }

    // IO object to handle input and output
    static class IO {
        private BufferedReader reader;
        private BufferedWriter writer;

        // Initialize IO object with standard input and output
        public IO() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        // Read a single byte from the input
        public byte scanByte() throws IOException {
            return Byte.parseByte(reader.readLine());
        }

        // Read a single string from the input
        public String scanString() throws IOException {
            return reader.readLine();
        }

        // Read multiple strings from the input
        public String[] scanStrings(int n) throws IOException {
            String[] strs = new String[n];
            for (int i = 0; i < n; i++) {
                strs[i] = scanString();
            }
            return strs;
        }

        // Read a 2D array of strings from the input
        public String[][] scan2DStrings(int y, int x) throws IOException {
            String[][] strs = new String[y][x];
            for (int i = 0; i < y; i++) {
                strs[i] = scanStrings(x);
            }
            return strs;
        }

        // Read a 2D array of graphs from the input
        public String[][] scan2DGraph(int y) throws IOException {
            String[][] strs = new String[y][];
            for (int i = 0; i < y; i++) {
                strs[i] = scanString().split("");
            }
            return strs;
        }

        // Read a single integer from the input
        public int scanInt() throws IOException {
            return Integer.parseInt(scanString());
        }

        // Read two integers from the input
        public int[] scanInt2() throws IOException {
            return new int[]{scanInt(), scanInt()};
        }

        // Read three integers from the input
        public int[] scanInt3() throws IOException {
            return new int[]{scanInt(), scanInt(), scanInt()};
        }

        // Read four integers from the input
        public int[] scanInt4() throws IOException {
            return new int[]{scanInt(), scanInt(), scanInt(), scanInt()};
        }

        // Read a slice of integers from the input
        public int[] scanInts(int n) throws IOException {
            int[] ints = new int[n];
            for (int i = 0; i < n; i++) {
                ints[i] = scanInt();
            }
            return ints;
        }

        // Read a 2D slice of integers from the input
        public int[][] scan2DInts(int y, int x) throws IOException {
            int[][] ints = new int[y][x];
            for (int i = 0; i < y; i++) {
                ints[i] = scanInts(x);
            }
            return ints;
        }

        // Read a single long from the input
        public long scanLong() throws IOException {
            return Long.parseLong(scanString());
        }

        // Read a single double from the input
        public double scanDouble() throws IOException {
            return Double.parseDouble(scanString());
        }

        // Read a slice of doubles from the input
        public double[] scanDoubles(int n) throws IOException {
            double[] doubles = new double[n];
            for (int i = 0; i < n; i++) {
                doubles[i] = scanDouble();
            }
            return doubles;
        }

        // Read a 2D slice of doubles from the input
        public double[][] scan2DDoubles(int y, int x) throws IOException {
            double[][] doubles = new double[y][x];
            for (int i = 0; i < y; i++) {
                doubles[i] = scanDoubles(x);
            }
            return doubles;
        }

        // Write a single line to the output
        public void println(Object... o) {
            try {
                writer.write(String.valueOf(o));
                writer.write("\n");
                writer.flush();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        // Flush the output buffer
        public void flush() {
            try {
                writer.flush();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        // Close the IO object
        public void close() {
            try {
                reader.close();
                writer.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

