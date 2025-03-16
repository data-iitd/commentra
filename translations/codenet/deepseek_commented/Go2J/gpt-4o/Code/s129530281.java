import java.io.*;
import java.util.*;

public class Main {
    // Scanner to read input
    private static Scanner scanner;

    // Main function handles file input, initializes a segment tree, and processes the input to compute an answer.
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
        }
        scanner = new Scanner(inputStream);
        PrintWriter writer = new PrintWriter(System.out);

        // Read the number of elements (n) and the number of operations (m).
        int n = getNextInt();
        int m = getNextInt();

        // Initialize the segment tree.
        Segment seg = new Segment();
        seg.init(n);

        // Populate the segment tree with initial values.
        for (int i = 0; i < n; i++) {
            seg.maximize(i, getNextInt());
        }

        // Perform the specified number of operations on the segment tree.
        for (int i = 0; i < m; i++) {
            seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
        }

        // Calculate the sum of the values in the root bucket of the segment tree.
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += seg.bucket[0][i];
        }

        // Write the result to the standard output.
        writer.println(ans);
        writer.flush();
    }

    // Get the next integer from the scanner.
    private static int getNextInt() {
        return scanner.nextInt();
    }

    // Segment class represents a segment tree and includes methods to initialize it and update/query it.
    static class Segment {
        int n, h, i, chunk;
        int[] unit;
        int[][] bucket;

        // init initializes the segment tree with a given size n.
        void init(int n) {
            this.n = n;
            unit = new int[1];
            unit[0] = 1;
            bucket = new int[1][n];

            chunk = 8;
            for (i = 0; n > 1; i++) {
                n = (n - 1) / chunk + 1;
                bucket = Arrays.copyOf(bucket, bucket.length + 1);
                bucket[bucket.length - 1] = new int[n];
                unit = Arrays.copyOf(unit, unit.length + 1);
                unit[unit.length - 1] = unit[i] * chunk;
            }
            h = unit.length;
        }

        // maximize updates the value at a given index in the segment tree.
        void maximize(int index, int value) {
            bucket[0][index] = value;
            for (i = 0; i < h - 1; i++) {
                int s = index - index % chunk;
                int t = s + chunk;
                if (t > bucket[i].length) {
                    t = bucket[i].length;
                }
                int parent = index / chunk;
                int max = 0;
                for (int j = s; j < t; j++) {
                    if (max < bucket[i][j]) {
                        max = bucket[i][j];
                    }
                }
                bucket[i + 1][parent] = max;
                index /= chunk;
            }
        }

        // top returns the index of the maximum value in the segment tree.
        int top() {
            int index = 0;
            for (i = h - 2; i >= 0; i--) {
                int s = index * chunk;
                int t = s + chunk;
                if (t > bucket[i].length) {
                    t = bucket[i].length;
                }
                for (int j = s; j < t; j++) {
                    if (bucket[i][j] == bucket[i + 1][index]) {
                        index = j;
                        break;
                    }
                }
            }
            return index;
        }
    }
}
// <END-OF-CODE>
