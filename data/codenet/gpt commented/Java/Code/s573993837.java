import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.BigInteger; 

public class Main {
    public static void main(String[] args) {
        // Initialize input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        
        // Call the solve function to process the input and produce output
        solve(in, out);
        
        // Close the output stream
        out.close();
    }

    // Declare global variables
    static int L, R, top, bottom;

    public static void solve(InputReader sc, PrintWriter pw) {
        // Number of test cases (currently set to 1)
        int t = 1;
        
        // Loop through each test case
        u: while (t-- > 0) {
            // Read two long integers from input
            long n = sc.nextLong();
            long m = sc.nextLong();
            
            // If n is zero, output 0 and continue to the next iteration
            if (n == 0) {
                pw.println(0);
                continue u;
            }
            
            // If n equals m, output 0 and continue to the next iteration
            if (n == m) {
                pw.println(0);
                continue u;
            }
            
            // If n is greater than m, adjust n and calculate the result
            if (n > m) {
                n = m + n % m; // Adjust n based on m
                n -= m; // Subtract m from the adjusted n
                pw.println(Math.min(m - n, n)); // Output the minimum of (m-n) and n
                continue u;
            }
            
            // Output the minimum of (m-n) and n when n is less than m
            pw.println(Math.min(m - n, n));
        }
    }

    // Method to swap two characters in an array
    public static void swap(char[] chrr, int i, int j) {
        char temp = chrr[i];
        chrr[i] = chrr[j];
        chrr[j] = temp;
    }

    // Method to count the number of 1s in the binary representation of n
    public static int num(int n) {
        int a = 0;
        while (n > 0) {
            a += (n & 1); // Increment count if the last bit is 1
            n >>= 1; // Right shift n to process the next bit
        }
        return a; // Return the count of 1s
    }

    // Class to represent a pair of integers with an additional index and value
    static class Pair {
        int u, v, i, val;

        // Constructor to initialize the Pair
        Pair(int a, int b, int i) {
            this.u = a;
            this.v = b;
            this.i = i;
        }
    }

    // Method to check if a number is prime
    static boolean isPrime(int n) {
        if (n <= 1) 
            return false; // Numbers less than or equal to 1 are not prime
        if (n <= 3) 
            return true; // 2 and 3 are prime numbers
        if (n % 2 == 0 || n % 3 == 0) 
            return false; // Exclude multiples of 2 and 3
        for (int i = 5; i * i <= n; i = i + 6) 
            if (n % i == 0 || n % (i + 2) == 0) 
                return false; // Check for factors from 5 onwards
        return true; // n is prime
    }

    // Method to compute the greatest common divisor (GCD) of two numbers
    static long gcd(long a, long b) {
        if (b == 0) 
            return a; // Base case: if b is 0, return a
        return a > b ? gcd(b, a % b) : gcd(a, b % a); // Recursive call
    }

    // Method to compute base^n % M using fast exponentiation
    static long fast_pow(long base, long n, long M) {
        if (n == 0)
            return 1; // Base case: any number to the power of 0 is 1
        if (n == 1)
            return base; // Base case: any number to the power of 1 is itself
        long halfn = fast_pow(base, n / 2, M); // Recursive call for half the exponent
        if (n % 2 == 0)
            return (halfn * halfn) % M; // If n is even
        else
            return (((halfn * halfn) % M) * base) % M; // If n is odd
    }

    // Method to compute modular inverse of n under modulo M
    static long modInverse(long n, long M) {
        return fast_pow(n, M - 2, M); // Using Fermat's Little Theorem
    }

    // Method to fill an array with long integers from input
    public static void feedArr(long[] arr, InputReader sc) {
        for (int i = 0; i < arr.length; i++)
            arr[i] = sc.nextLong(); // Read each long integer
    }

    // Method to fill an array with double values from input
    public static void feedArr(double[] arr, InputReader sc) {
        for (int i = 0; i < arr.length; i++)
            arr[i] = sc.nextDouble(); // Read each double value
    }

    // Method to fill an array with integers from input
    public static void feedArr(int[] arr, InputReader sc) {
        for (int i = 0; i < arr.length; i++)
            arr[i] = sc.nextInt(); // Read each integer
    }

    // Method to fill an array with strings from input
    public static void feedArr(String[] arr, InputReader sc) {
        for (int i = 0; i < arr.length; i++)
            arr[i] = sc.next(); // Read each string
    }

    // Method to print an array of integers as a string
    public static String printArr(int[] arr) {
        StringBuilder sbr = new StringBuilder();
        for (int i : arr)
            sbr.append(i + " "); // Append each integer to the StringBuilder
        return sbr.toString(); // Return the constructed string
    }

    // Method to print an array of long integers as a string
    public static String printArr(long[] arr) {
        StringBuilder sbr = new StringBuilder();
        for (long i : arr)
            sbr.append(i + " "); // Append each long integer to the StringBuilder
        return sbr.toString(); // Return the constructed string
    }

    // Method to print an array of strings as a single string
    public static String printArr(String[] arr) {
        StringBuilder sbr = new StringBuilder();
        for (String i : arr)
            sbr.append(i + " "); // Append each string to the StringBuilder
        return sbr.toString(); // Return the constructed string
    }

    // Method to print an array of double values as a string
    public static String printArr(double[] arr) {
        StringBuilder sbr = new StringBuilder();
        for (double i : arr)
            sbr.append(i + " "); // Append each double value to the StringBuilder
        return sbr.toString(); // Return the constructed string
    }

    // Class to read input from the console
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        // Constructor to initialize the InputReader
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        // Method to read the next token as a string
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine()); // Read a new line
                } catch (IOException e) {
                    throw new RuntimeException(e); // Handle IO exceptions
                }
            }
            return tokenizer.nextToken(); // Return the next token
        }

        // Method to read the next token as an integer
        public int nextInt() {
            return Integer.parseInt(next()); // Parse and return the next token as an integer
        }

        // Method to read the next token as a long
        public long nextLong() {
            return Long.parseLong(next()); // Parse and return the next token as a long
        }

        // Method to read the next token as a double
        public double nextDouble() {
            return Double.parseDouble(next()); // Parse and return the next token as a double
        }
    }
}
