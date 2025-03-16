import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        IO io = new IO();
        int n = io.scanInt();
        double t = io.scanFloat64();
        double a = io.scanFloat64();
        double[] heights = io.scanFloat64s(n);

        double minDiff = absDiff(t - heights[0] * 0.006, a);
        int minIdx = 0;
        for (int i = 1; i < heights.length; i++) {
            double diff = absDiff(t - heights[i] * 0.006, a);
            if (diff < minDiff) {
                minDiff = diff;
                minIdx = i;
            }
        }
        System.out.println(minIdx + 1);
    }

    public static double absDiff(double n1, double n2) {
        return Math.abs(n1 - n2);
    }

    static class IO {
        private final Scanner scanner;

        public IO() {
            this.scanner = new Scanner(System.in);
        }

        public int scanInt() {
            return Integer.parseInt(scanString());
        }

        public double scanFloat64() {
            return Double.parseDouble(scanString());
        }

        public double[] scanFloat64s(int n) {
            double[] floats = new double[n];
            for (int i = 0; i < n; i++) {
                floats[i] = scanFloat64();
            }
            return floats;
        }

        public String scanString() {
            return scanner.next();
        }
    }
}
