package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        IO io = new IO();
        try {
            int n = io.nextInt();
            double t = io.nextDouble();
            double a = io.nextDouble();
            double[] heights = io.nextDoubles(n);

            double minDiff = Math.abs(t - heights[0] * 0.006);
            int minIdx = 0;
            for (int i = 1; i < n; i++) {
                double diff = Math.abs(t - heights[i] * 0.006);
                if (diff < minDiff) {
                    minDiff = diff;
                    minIdx = i;
                }
            }
            io.println(minIdx + 1);
        } finally {
            io.close();
        }
    }
}

class IO {
    private BufferedReader reader;
    private BufferedWriter writer;

    public IO() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        writer = new BufferedWriter(new OutputStreamWriter(System.out));
    }

    public void close() throws IOException {
        reader.close();
        writer.close();
    }

    public String next() throws IOException {
        return reader.readLine();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public String[] nextStrings(int n) throws IOException {
        String[] strs = new String[n];
        for (int i = 0; i < n; i++) {
            strs[i] = next();
        }
        return strs;
    }

    public int[] nextInts(int n) throws IOException {
        int[] ints = new int[n];
        for (int i = 0; i < n; i++) {
            ints[i] = nextInt();
        }
        return ints;
    }

    public long[] nextLongs(int n) throws IOException {
        long[] longs = new long[n];
        for (int i = 0; i < n; i++) {
            longs[i] = nextLong();
        }
        return longs;
    }

    public double[] nextDoubles(int n) throws IOException {
        double[] doubles = new double[n];
        for (int i = 0; i < n; i++) {
            doubles[i] = nextDouble();
        }
        return doubles;
    }

    public void println(String s) throws IOException {
        writer.write(s);
        writer.write("\n");
    }
}

