import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize the reader and writer
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        
        // Read the number of integers
        int n = nextInt(reader);
        // Read the integers into an array
        int[] a = nextInts(reader, n);

        // Initialize the answer counter
        int ans = 0;

        // Iterate through the array of integers
        for (int i = 0; i < n; i++) {
            // Set the left and right pointers for the current segment
            int l = i, r = i + 1;

            // Expand the right pointer while the conditions are met
            while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
                r++;
            }

            // Increment the answer for each segment found
            ans++;
            // Move the left pointer to the end of the current segment
            i = r;
        }

        // Output the final count of segments
        writer.write(String.valueOf(ans));
        writer.newLine();
        // Flush the buffered writer to ensure all output is written
        writer.flush();
    }

    // Function to read the next integer from input
    private static int nextInt(BufferedReader reader) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        return Integer.parseInt(tokenizer.nextToken());
    }

    // Function to read a slice of integers from input
    private static int[] nextInts(BufferedReader reader, int n) throws IOException {
        int[] slice = new int[n];
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            slice[i] = Integer.parseInt(tokenizer.nextToken());
        }
        return slice;
    }
}

// <END-OF-CODE>
