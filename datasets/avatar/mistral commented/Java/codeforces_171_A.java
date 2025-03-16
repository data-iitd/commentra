// Importing necessary classes
import java.io.* ;
import java.util.* ;

// Defining a static inner class FastReader for reading input
public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        // Constructor for FastReader
        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        // Method for reading next token
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

        // Methods for reading specific types of input
        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "" ;
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    // Main method
    public static void main(String[] args) {
        // Creating an instance of FastReader
        FastReader sc = new FastReader();

        // Reading input for number of test cases
        int n = sc.nextInt();

        // Reading input for number of operations
        int m = sc.nextInt();

        // Calling reverse function for m and adding it to n
        int t = reverse(m);
        System.out.println(t + n);
    }

    // Function for reversing a number
    public static int reverse(int n) {
        // Base case for numbers less than 10
        if (n < 10)
            return n * 10;

        // Initializing variables
        int t = n, r = 0;

        // Reversing the number
        while (t > 0) {
            // Adding the digit to the reversed number
            r = (r * 10) + t % 10;

            // Moving to the next digit
            t = t / 10;
        }

        // Returning the reversed number
        return r;
    }
}
