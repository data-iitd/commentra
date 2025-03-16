
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class s129530281{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        StringTokenizer st;

        // Determine the input source: either standard input or a file specified as a command-line argument
        BufferedReader reader = br;
        if (args.length > 0) {
            reader = new BufferedReader(new FileReader(args[0])); // Open the file if an argument is provided
        }

        // Read the number of elements and operations
        int n = Integer.parseInt(reader.readLine());
        int m = Integer.parseInt(reader.readLine());

        // Initialize the Segment structure
        Segment seg = new Segment();
        seg.init(n); // Initialize the segment with size n

        // Populate the segment with initial values
        for (int i = 0; i < n; i++) {
            seg.maximize(i, Integer.parseInt(reader.readLine())); // Maximize the segment with the input values
        }

        // Perform m operations to maximize the segment
        for (int i = 0; i < m; i++) {
            seg.maximize(seg.top(), seg.bucket[seg.h - 1][0] >> 1); // Maximize using the top value and half of the last bucket's first element
        }

        // Calculate the final answer by summing up the values in the first bucket
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += seg.bucket[0][i]; // Accumulate the values
        }

        // Output the final result
        out.println(ans);
        out.flush(); // Flush the output stream

        reader.close(); // Close the input reader
        br.close(); // Close the buffered reader
        out.close(); // Close the output writer
    }

    // Segment structure to hold the segment data and operations
    static class Segment {
        int n, h, i, chunk;
        int[] unit;
        int[][] bucket;

        // init initializes the segment structure with the given size n.
        void init(int n) {
            this.n = n;
            unit = new int[1]; // Initialize unit array
            unit[0] = 1;
            bucket = new int[1][n];

            chunk = 8; // Define the chunk size
            for (int i = 0; n > 1; i++) {
                n = (n - 1) / chunk + 1; // Reduce n based on the chunk size
                bucket = Arrays.copyOf(bucket, bucket.length + 1); // Append a new bucket
                unit = Arrays.copyOf(unit, unit.length + 1); // Update unit array
                unit[i + 1] = unit[i] * chunk;
            }
            h = unit.length; // Set the height of the segment
        }

        // maximize updates the segment at a given index with a new value.
        void maximize(int index, int value) {
            bucket[0][index] = value; // Set the value in the first bucket
            for (i = 0; i < h - 1; i++) {
                int s = index - index % chunk; // Calculate the start of the current chunk
                int t = s + chunk; // Calculate the end of the current chunk
                if (t > bucket[i].length) {
                    t = bucket[i].length; // Adjust end if it exceeds the bucket length
                }
                int parent = index / chunk; // Determine the parent index
                int max = 0; // Initialize max value
                for (int j = s; j < t; j++) {
                    if (max < bucket[i][j]) {
                        max = bucket[i][j]; // Find the maximum value in the current chunk
                    }
                }
                bucket[i + 1][parent] = max; // Update the parent bucket with the maximum value
                index /= chunk; // Move to the parent index for the next iteration
            }
        }

        // top retrieves the index of the top value in the segment.
        int top() {
            int index = 0; // Start from the root index
            for (i = h - 2; i >= 0; i--) {
                int s = index * chunk; // Calculate the start of the current chunk
                int t = s + chunk; // Calculate the end of the current chunk
                if (t > bucket[i].length) {
                    t = bucket[i].length; // Adjust end if it exceeds the bucket length
                }
                for (int j = s; j < t; j++) {
                    if (bucket[i][j] == bucket[i + 1][index]) {
                        index = j; // Update index if the value matches the top value
                        break;
                    }
                }
            }

            return index; // Return the index of the top value
        }
    }
}

