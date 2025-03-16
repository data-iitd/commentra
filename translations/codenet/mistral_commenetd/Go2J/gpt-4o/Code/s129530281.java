// Import necessary packages
import java.io.*;
import java.util.*;

// Main class
public class Main {
    // Main method is the entry point of the program
    public static void main(String[] args) throws IOException {
        // Open the standard input file if a command-line argument is provided
        InputStream inputStream = System.in;
        if (args.length > 0) {
            inputStream = new FileInputStream(args[0]);
        }
        Scanner scanner = new Scanner(inputStream);

        // Read the first two integers from the input
        int n = getNextInt(scanner);
        int m = getNextInt(scanner);

        // Initialize the Segment struct with the given size n
        Segment seg = new Segment();
        seg.init(n);

        // Process the input data by maximizing the segments
        for (int i = 0; i < n; i++) {
            seg.maximize(i, getNextInt(scanner));
        }
        for (int i = 0; i < m; i++) {
            seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1);
        }

        // Calculate the answer and print it to the output
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += seg.bucket[0][i];
        }

        // Print the answer to the output
        System.out.println(ans);
    }

    // Function to get the next integer from the scanner
    private static int getNextInt(Scanner scanner) {
        return Integer.parseInt(scanner.next());
    }

    // Segment class represents a segment tree data structure
    static class Segment {
        int n, h, i, chunk;
        int[] unit;
        int[][] bucket;

        // Init function initializes the Segment struct with the given size n
        void init(int n) {
            this.n = n;
            unit = new int[1];
            unit[0] = 1;
            bucket = new int[1][n];

            // Calculate the chunk size for the segment tree
            int chunk = 8;
            while (n > 1) {
                n = (n - 1) / chunk + 1;
                bucket = Arrays.copyOf(bucket, bucket.length + 1);
                bucket[bucket.length - 1] = new int[n];
                unit = Arrays.copyOf(unit, unit.length + 1);
                unit[unit.length - 1] = unit[unit.length - 2] * chunk;
            }
            h = unit.length;
            this.chunk = chunk;
        }

        // Maximize function updates the segment tree with the given index and value
        void maximize(int index, int value) {
            // Update the leaf node with the given index and value
            bucket[0][index] = value;

            // Propagate the update to the parent nodes
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

        // Top function returns the index of the maximum value in the current segment
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
