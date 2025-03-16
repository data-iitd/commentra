import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    // Task class to encapsulate the problem-solving logic
    static class Task {

        // Method to solve the problem for a given test case
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            // Read the integer n from input
            int n = in.nextInt();
            // Initialize an array to count occurrences of each possible value
            int[] countArr = new int[n + 1];

            // Iterate through all combinations of x, y, z from 1 to 100
            for (int x = 1; x <= 100; x++) {
                for (int y = 1; y <= 100; y++) {
                    for (int z = 1; z <= 100; z++) {
                        // Calculate the value based on the formula
                        int value = x * x + y * y + z * z + x * y + x * z + y * z;
                        // If the value exceeds n, break out of the loop
                        if (value > n) {
                            break;
                        }
                        // Increment the count for the calculated value
                        countArr[value]++;
                    }
                }
            }

            // Output the counts for each value from 1 to n
            for (int i = 1; i <= n; i++) {
                out.println(countArr[i]);
            }
        }
    }

    // Generic method to sort an array of doubles
    private static void sort(double[] arr) {
        // Convert primitive double array to Double object array for sorting
        Double[] objArr = Arrays.stream(arr).boxed().toArray(Double[]::new);
        // Sort the object array
        Arrays.sort(objArr);
        // Copy sorted values back to the original array
        for (int i = 0; i < arr.length; i++) {
            arr[i] = objArr[i];
        }
    }

    // Generic method to sort an array of integers
    private static void sort(int[] arr) {
        // Convert primitive int array to Integer object array for sorting
        Integer[] objArr = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        // Sort the object array
        Arrays.sort(objArr);
        // Copy sorted values back to the original array
        for (int i = 0; i < arr.length; i++) {
            arr[i] = objArr[i];
        }
    }

    // Generic method to sort an array of longs
    private static void sort(long[] arr) {
        // Convert primitive long array to Long object array for sorting
        Long[] objArr = Arrays.stream(arr).boxed().toArray(Long[]::new);
        // Sort the object array
        Arrays.sort(objArr);
        // Copy sorted values back to the original array
        for (int i = 0; i < arr.length; i++) {
            arr[i] = objArr[i];
        }
    }

    // Method to set up input and output streams and invoke the task solver
    private static void solve() {
        // Set up input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        // Create a Task instance and solve the problem
        Task task = new Task();
        task.solve(1, in, out);
        // Close the output stream
        out.close();
    }

    // Main method to start the program
    public static void main(String[] args) {
        // Start a new thread to execute the solve method
        new Thread(null, () -> solve(), "1", 1 << 26).start();
    }

    // InputReader class to handle input reading
    static class InputReader {

        public BufferedReader reader; // BufferedReader for reading input
        public StringTokenizer tokenizer; // Tokenizer for parsing input

        // Constructor to initialize the InputReader with an InputStream
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        // Method to read the next token as a String
        public String next() {
            // Ensure there are tokens available to read
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        // Method to read the next token as an integer
        public int nextInt() {
            return Integer.parseInt(next());
        }

        // Method to read the next token as a long
        public long nextLong() {
            return Long.parseLong(next());
        }

        // Method to read the next token as a double
        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
