import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize input/output handling
        Io io = new Io();
        
        // Read the number of elements
        int n = io.nextInt();

        // Create a list to hold the input integers
        List<Integer> aa = new ArrayList<>();

        // Read each integer and store it in the list
        for (int i = 0; i < n; i++) {
            aa.add(io.nextInt());
        }

        // Compute the cumulative sum of the input integers
        List<Integer> cumsum = cumSum(aa);

        // Initialize the answer with a large value
        int ans = 2020202020;

        // Iterate through the cumulative sums to find the minimum difference
        for (int i = 1; i < cumsum.size() - 1; i++) {
            ans = Math.min(ans, Math.abs(cumsum.get(cumsum.size() - 1) - cumsum.get(i) - (cumsum.get(i) - cumsum.get(0))));
        }

        // Output the final answer
        System.out.println(ans);
    }

    // Io class for handling input and output
    static class Io {
        private BufferedReader reader;
        private PrintWriter writer;
        private StringTokenizer tokenizer;

        public Io() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
        }

        public void flush() {
            writer.flush();
        }

        public String nextLine() throws IOException {
            return reader.readLine();
        }

        public String next() throws IOException {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(nextLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public void print(Object... args) {
            for (Object arg : args) {
                writer.print(arg + " ");
            }
        }

        public void println(Object... args) {
            print(args);
            writer.println();
        }
    }

    // CumSum computes the cumulative sum of a list of integers
    static List<Integer> cumSum(List<Integer> nums) {
        List<Integer> sums = new ArrayList<>();
        sums.add(0);
        for (int num : nums) {
            sums.add(sums.get(sums.size() - 1) + num);
        }
        return sums;
    }
}
