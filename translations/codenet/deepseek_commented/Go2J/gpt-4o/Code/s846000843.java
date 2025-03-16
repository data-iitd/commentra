import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Io io = new Io();
        int n = io.nextInt(); // Read the number of integers.

        int[] aa = new int[n];
        for (int i = 0; i < n; i++) {
            aa[i] = io.nextInt(); // Read each integer and store it in the array.
        }

        int[] cumsum = cumSum(aa); // Compute the cumulative sum of the integers.

        int ans = 2020202020;
        for (int i = 1; i < cumsum.length - 1; i++) {
            ans = Math.min(ans, Math.abs(cumsum[cumsum.length - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
        }

        System.out.println(ans); // Print the minimum absolute difference.
    }

    // Io class for handling input and output.
    static class Io {
        private BufferedReader reader;
        private PrintWriter writer;
        private StringTokenizer tokenizer;

        public Io() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
        }

        public void flush() {
            writer.flush(); // Ensure all buffered data is written to the underlying writer.
        }

        public String nextLine() throws IOException {
            return reader.readLine(); // Read the next line of input from the reader.
        }

        public String next() throws IOException {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(nextLine());
            }
            return tokenizer.nextToken(); // Read the next token from the input.
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next()); // Read the next token as an integer.
        }

        public void printLn(Object... args) {
            for (Object arg : args) {
                writer.print(arg + " ");
            }
            writer.println(); // Print the arguments to the writer with a newline.
        }

        public void printf(String format, Object... args) {
            writer.printf(format, args); // Format and print the arguments to the writer.
        }
    }

    // CumSum computes the cumulative sum of an array of integers.
    static int[] cumSum(int[] nums) {
        int[] sums = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return sums;
    }
}
