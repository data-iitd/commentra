package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Initialize input/output handling
        IO io = new IO();
        // Read the number of heights, target temperature, and actual temperature
        int n = io.scanInt();
        double t = io.scanDouble();
        double a = io.scanDouble();
        // Read the heights as a slice of float64
        double[] heights = io.scanDoubles(n);

        // Initialize minimum difference and index for tracking the closest height
        double minDiff = Math.abs(t - heights[0] * 0.006);
        int minIdx = 0;

        // Iterate through the heights to find the one with the minimum temperature difference
        for (int i = 1; i < heights.length; i++) {
            double diff = Math.abs(t - heights[i] * 0.006);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i; // Update the index of the closest height
            }
        }

        // Output the 1-based index of the closest height
        io.println(minIdx + 1);
    }

    // IO class for handling input and output operations
    public static class IO {

        private BufferedReader reader;
        private BufferedWriter writer;

        // Initialize input/output handling
        public IO() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        // Read and return a line of input
        public String scanLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        // Read and return a single word
        public String scanWord() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        // Read and return a single integer
        public int scanInt() {
            try {
                return Integer.parseInt(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        // Read and return a single double
        public double scanDouble() {
            try {
                return Double.parseDouble(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        // Read and return an array of integers
        public int[] scanInts(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = scanInt();
            }
            return arr;
        }

        // Read and return an array of doubles
        public double[] scanDoubles(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = scanDouble();
            }
            return arr;
        }

        // Read and return a 2D array of integers
        public int[][] scan2DInts(int y, int x) {
            int[][] arr = new int[y][x];
            for (int i = 0; i < y; i++) {
                arr[i] = scanInts(x);
            }
            return arr;
        }

        // Read and return a 2D array of doubles
        public double[][] scan2DDoubles(int y, int x) {
            double[][] arr = new double[y][x];
            for (int i = 0; i < y; i++) {
                arr[i] = scanDoubles(x);
            }
            return arr;
        }

        // Read and return a 2D array of strings
        public String[][] scan2DStrings(int y, int x) {
            String[][] arr = new String[y][x];
            for (int i = 0; i < y; i++) {
                arr[i] = scanStrings(x);
            }
            return arr;
        }

        // Read and return a 2D array of strings representing a graph
        public String[][] scan2DGraph(int y) {
            String[][] arr = new String[y][];
            for (int i = 0; i < y; i++) {
                arr[i] = scanLine().split("");
            }
            return arr;
        }

        // Write a line of output
        public void println(Object... objects) {
            try {
                for (Object object : objects) {
                    writer.write(object.toString());
                    writer.write(" ");
                }
                writer.write("\n");
                writer.flush();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

