import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // Task class contains the main logic for solving the problem
    static class Task {

        // Solve method is the entry point for solving the problem
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            // Read the value of n
            int n = in.nextInt();
            // Initialize an array to count the frequency of each value
            int[] countArr = new int[n + 1];
            // Iterate over possible values of x, y, and z
            for (int x = 1; x <= 100; x++) {
                for (int y = 1; y <= 100; y++) {
                    for (int z = 1; z <= 100; z++) {
                        // Calculate the value based on the given formula
                        int value = x * x + y * y + z * z + x * y + x * z + y * z;
                        // Break the loop if the value exceeds n
                        if (value > n) {
                            break;
                        }
                        // Update the count of the calculated value
                        countArr[value]++;
                    }
                }
            }

            // Output the frequency of each value from 1 to n
            for (int i = 1; i <= n; i++) {
                out.println(countArr[i]);
            }
        }
    }

    // Utility method to sort an array of doubles
    private static void sort(double[] arr) {
        Double[] objArr = Arrays.stream(arr).boxed().toArray(Double[]::new);
        Arrays.sort(objArr);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = objArr[i];
        }
    }

    // Utility method to sort an array of integers
    private static void sort(int[] arr) {
        Integer[] objArr = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        Arrays.sort(objArr);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = objArr[i];
        }
    }

    // Utility method to sort an array of longs
    private static void sort(long[] arr) {
        Long[] objArr = Arrays.stream(arr).boxed().toArray(Long[]::new);
        Arrays.sort(objArr);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = objArr[i];
        }
    }

    // Main method to set up the input/output streams and solve the problem
    private static void solve() {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task task = new Task();
        task.solve(1, in, out);
        out.close();
    }

    // Main method to start the thread that runs the solve method
    public static void main(String[] args) {
        new Thread(null, () -> solve(), "1", 1 << 26).start();
    }

    // InputReader class to read input from the standard input stream
    static class InputReader {

        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }

}
