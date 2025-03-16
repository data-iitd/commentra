
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static class Task {

        // Define a class to represent a single test case
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            // Read the number of test cases to process
            int n = in.nextInt();
            // Initialize an array to store the count of each number
            int[] countArr = new int[n + 1];
            // Iterate through all possible combinations of x, y, and z
            for (int x = 1; x <= 100; x++) {
                for (int y = 1; y <= 100; y++) {
                    for (int z = 1; z <= 100; z++) {
                        // Calculate the value of the current combination
                        int value = x * x + y * y + z * z + x * y + x * z + y * z;
                        // If the value is greater than the total number, break the loop
                        if (value > n) {
                            break;
                        }
                        // Increment the count of the current value
                        countArr[value]++;
                    }
                }
            }

            // Iterate through the array and print the count of each number
            for (int i = 1; i <= n; i++) {
                out.println(countArr[i]);
            }
        }
    }

    // Define helper methods to sort arrays of different types
    private static void sort(double[] arr) {
        Double[] objArr = Arrays.stream(arr).boxed().toArray(Double[]::new);
        // Use Arrays.sort to sort the object array and then copy the sorted elements back to the original array
        Arrays.sort(objArr);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = objArr[i];
        }
    }

    private static void sort(int[] arr) {
        Integer[] objArr = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        Arrays.sort(objArr);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = objArr[i];
        }
    }

    private static void sort(long[] arr) {
        Long[] objArr = Arrays.stream(arr).boxed().toArray(Long[]::new);
        Arrays.sort(objArr);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = objArr[i];
        }
    }

    // Define a method to solve the problem
    private static void solve() {
        // Initialize input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        // Create an instance of the Task class and call its solve method
        Task task = new Task();
        task.solve(1, in, out);
        // Close the output stream
        out.close();
    }

    // Define the main method to start the program
    public static void main(String[] args) {
        // Start a new thread to solve the problem and run it
        new Thread(null, () -> solve(), "1", 1 << 26).start();
    }

    // Define a class to read input
    static class InputReader {

        // Initialize the reader and tokenizer
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        // Define methods to read different types of input
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