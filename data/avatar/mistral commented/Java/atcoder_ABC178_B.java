
import java.util.* ;  // Importing necessary Java utility classes
import java.lang.* ;  // Importing necessary Java language classes
import java.io.* ;   // Importing necessary Java I/O classes

public class Main {

    static class FastReader {      // Defining a FastReader class for reading input
        BufferedReader br;         // Declaring a BufferedReader object for reading lines
        StringTokenizer st;        // Declaring a StringTokenizer object for tokenizing lines

        public FastReader() {       // Constructor for initializing the FastReader object
            br = new BufferedReader(new InputStreamReader(System.in)); // Initializing the BufferedReader object
        }

        String next() {             // Method for reading the next token from the input
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine()); // Creating a new StringTokenizer object for the current line
                } catch (IOException e) {
                    e.printStackTrace(); // Printing an error message if an I/O exception occurs
                }
            }
            return st.nextToken(); // Returning the next token
        }

        int nextInt() {             // Method for reading the next integer from the input
            return Integer.parseInt(next()); // Converting the next token to an integer and returning it
        }

        long nextLong() {           // Method for reading the next long integer from the input
            return Long.parseLong(next()); // Converting the next token to a long integer and returning it
        }

        double nextDouble() {       // Method for reading the next double from the input
            return Double.parseDouble(next()); // Converting the next token to a double and returning it
        }

        String nextLine() {         // Method for reading the next line from the input
            String str = "" ;       // Initializing an empty String variable for storing the line
            try {
                str = br.readLine(); // Reading the next line and storing it in the String variable
            } catch (Exception e) {
                e.printStackTrace(); // Printing an error message if an exception occurs
            }
            return str; // Returning the next line
        }
    }

    static int modPower(int x, int y, int mod) { // Method for calculating x raised to the power of y modulo mod
        int res = 1; // Initializing the result variable to 1
        x %= mod; // Calculating the remainder of x when divided by mod

        if (x == 0) return 0; // If x is 0, the result is 0

        while (y > 0) { // While y is greater than 0
            if (y % 2 == 1) { // If y is odd
                res = (res * x) % mod; // Multiplying the result with x and taking the modulo with mod
            }
            y = y >> 1; // Dividing y by 2
            x = (x * x) % mod; // Squaring x and taking the modulo with mod
        }
        return res; // Returning the final result
    }

    static class pair <T1, T2> { // Defining a generic pair class for storing two elements of different types
        T1 first; // Declaring a variable for storing the first element
        T2 second; // Declaring a variable for storing the second element

        pair(T1 first, T2 second) { // Constructor for initializing the pair object
            this.first = first; // Initializing the first variable with the first argument
            this.second = second; // Initializing the second variable with the second argument
        }
    }

    public static void main(String[] args) throws java.lang.Exception { // Main method for executing the program
        FastReader in = new FastReader(); // Creating a FastReader object for reading input

        long[] a = new long[4]; // Declaring and initializing an array of long integers named a with size 4

        for (int i = 0; i < 4; i++) { // Iterating through the elements of the array a
            a[i] = in.nextLong(); // Reading the next long integer from the input and storing it in the current element of the array
        }

        long result = Math.max(a[0] * a[2], Math.max(a[1] * a[3], Math.max(a[0] * a[3], a[1] * a[2]))); // Calculating the maximum product of pairs of elements in the array a

        System.out.println(result); // Printing the result to the standard output
    }
}

These comments should provide a clear understanding of the code for anyone who reads it.