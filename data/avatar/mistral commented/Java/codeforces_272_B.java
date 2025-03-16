
import java.io.BufferedReader;  // Import BufferedReader for reading input
import java.io.IOException;        // Import IOException for handling input/output errors
import java.io.InputStreamReader;  // Import InputStreamReader for reading input from the console
import java.io.PrintWriter;        // Import PrintWriter for writing output
import java.util.StringTokenizer;  // Import StringTokenizer for tokenizing input

public class Main {

    // Initialize FastReader for reading input
    public static void main(String[] args) {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        // Read the number of test cases
        int n = sc.nextInt();

        // Initialize an array 'a' to store the frequency of each number
        int a[] = new int[33];

        // Read each test case and update the frequency of the number in the array 'a'
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt(); // Read a number
            int index = rec(num);   // Get the index of the number in the array 'a'
            a[index]++;             // Increment the frequency of the number in the array 'a'
        }

        // Calculate the answer and print it
        double answer = 0;
        for (int i = 0; i < a.length; i++) {
            double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1); // Calculate the sum of squares of numbers up to the current number
            answer += summ;                                 // Add the sum to the answer
        }
        out.println((long) answer); // Print the answer as a long integer
        out.close();              // Close the PrintWriter
    }

    // A helper method to get the index of a number in the array 'a'
    static int rec(long x) {
        int answer = 0;

        // Calculate the index of the number in the array 'a' by counting the number of set bits in the binary representation of the number
        for (int k = 31; k >= 0; k--) {
            if ((x & (1 << k)) != 0) // If the k-th bit is set
                answer++;             // Increment the answer
        }

        return answer;
    }

    // A custom InputReader class for reading input efficiently
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        // Initialize the FastReader
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        // Read a string token
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        // Read an integer
        int nextInt() {
            return Integer.parseInt(next());
        }

        // Read a long integer
        long nextLong() {
            return Long.parseLong(next());
        }

        // Read a double
        double nextDouble() {
            return Double.parseDouble(next());
        }

        // Read a line
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}

These comments should provide a clear understanding of the code for anyone who reads it.