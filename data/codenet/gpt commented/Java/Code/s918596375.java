import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        // Initialize FastScanner to read input from standard input
        FastScanner sc = new FastScanner(System.in);
        // Initialize PrintWriter to output results to standard output
        PrintWriter out = new PrintWriter(System.out);

        // Call the solve method to process the input and produce output
        solve(sc, out);

        // Flush the output to ensure all data is written out
        out.flush();
    }

    public static void solve(FastScanner sc, PrintWriter out) {
        // Read a single string input
        String s = sc.next();
        
        // Array of vowel characters
        String[] a = {"a", "e", "i", "o", "u"};
        
        // Check if the input string is a vowel
        for (String str : a) {
            if (str.equalsIgnoreCase(s)) {
                out.println("vowel"); // Output "vowel" if the input matches
                return; // Exit the method after finding a match
            }
        }
        
        // If no match was found, output "consonant"
        out.println("consonant");
    }

    // Method to compute the greatest common divisor (GCD) of two integers
    public static int gcd(int a, int b) {
        if (a < b) return gcd(b, a); // Ensure a is greater than b
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a % b); // Recursive call to find GCD
    }

    // Overloaded method to compute the GCD of two long integers
    public static long gcd(long a, long b) {
        if (a < b) return gcd(b, a); // Ensure a is greater than b
        if (b == 0) return a; // Base case: if b is 0, return a
        return gcd(b, a % b); // Recursive call to find GCD
    }

    // Method to compute the least common multiple (LCM) of two integers
    public static int lcm(int a, int b) {
        return (a * b) / gcd(a, b); // LCM is calculated using GCD
    }
}

// Pair class to hold a key-value pair
class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> {

    // Constructor to initialize the Pair with a key and value
    public Pair(final K key, final V value) {
        super(key, value);
    }

    // Method to swap the key and value of the Pair
    public Pair<V, K> swap() {
        return new Pair<V, K>(getValue(), getKey());
    }
}

// FastScanner class for efficient input reading
class FastScanner {
    private BufferedReader reader = null; // BufferedReader for reading input
    private StringTokenizer tokenizer = null; // Tokenizer for parsing input

    // Constructor to initialize the FastScanner with an InputStream
    public FastScanner(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
        tokenizer = null; // Initialize tokenizer to null
    }

    // Method to read the next token from input
    public String next() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine()); // Read a new line and tokenize it
            } catch (IOException e) {
                throw new RuntimeException(e); // Handle IOException
            }
        }
        return tokenizer.nextToken(); // Return the next token
    }

    // Method to read the next line from input
    public String nextLine() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                return reader.readLine(); // Read and return the entire line
            } catch (IOException e) {
                throw new RuntimeException(e); // Handle IOException
            }
        }

        return tokenizer.nextToken("\n"); // Return the next token until newline
    }

    // Method to read the next long integer from input
    public long nextLong() {
        return Long.parseLong(next()); // Parse and return the next token as long
    }

    // Method to read the next integer from input
    public int nextInt() {
        return Integer.parseInt(next()); // Parse and return the next token as int
    }

    // Method to read the next double from input
    public double nextDouble() {
        return Double.parseDouble(next()); // Parse and return the next token as double
    }

    // Method to read an array of integers from input
    public int[] nextIntArray(int n) {
        int[] a = new int[n]; // Create an array of size n
        for (int i = 0; i < n; i++)
            a[i] = nextInt(); // Fill the array with integers from input
        return a; // Return the filled array
    }

    // Method to read an array of long integers from input
    public long[] nextLongArray(int n) {
        long[] a = new long[n]; // Create an array of size n
        for (int i = 0; i < n; i++)
            a[i] = nextLong(); // Fill the array with long integers from input
        return a; // Return the filled array
    }
}
