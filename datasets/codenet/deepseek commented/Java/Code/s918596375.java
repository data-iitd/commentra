import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.StringTokenizer;

public class Main {

    // Main method is the entry point of the program.
    // It initializes a FastScanner and PrintWriter, then calls the solve method.
    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        solve(sc, out); // Process the input and output the result.

        out.flush(); // Ensure all buffered output is written to the output stream.
    }

    // The solve method reads a string, checks if it is a vowel or consonant, and prints the result.
    public static void solve(FastScanner sc, PrintWriter out) {
        String s = sc.next(); // Read the next token as a string.

        String[] a = {"a", "e", "i", "o", "u"}; // Array of vowels.

        // Iterate through the array of vowels and check if the input string is a vowel.
        for (String str : a) {
            if (str.equalsIgnoreCase(s)) { // Check if the input string matches any vowel (case-insensitive).
                out.println("vowel"); // Print "vowel" if it is a vowel.
                return; // Exit the method after printing the result.
            }
        }

        out.println("consonant"); // Print "consonant" if the input string is not a vowel.
    }

    // Computes the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
    public static int gcd(int a, int b) {
        if (a < b) return gcd(b, a); // Ensure a >= b.
        if (b == 0) return a; // Base case: if b is 0, return a.
        return gcd(b, a % b); // Recursive call with b and the remainder of a divided by b.
    }

    // Computes the greatest common divisor (GCD) of two long integers using the Euclidean algorithm.
    public static long gcd(long a, long b) {
        if (a < b) return gcd(b, a); // Ensure a >= b.
        if (b == 0) return a; // Base case: if b is 0, return a.
        return gcd(b, a % b); // Recursive call with b and the remainder of a divided by b.
    }

    // Computes the least common multiple (LCM) of two integers using the relationship between GCD and LCM.
    public static int lcm(int a, int b) {
        return (a * b) / gcd(a, b); // LCM is calculated using the formula: (a * b) / GCD(a, b).
    }
}

// A generic pair class extending AbstractMap.SimpleEntry to create a key-value pair.
class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> {

    public Pair(final K key, final V value) {
        super(key, value);
    }

    // Method to swap the key and value in the pair.
    public Pair<V, K> swap() {
        return new Pair<V, K>(getValue(), getKey());
    }
}

// FastScanner class to read input efficiently using BufferedReader and StringTokenizer.
class FastScanner {
    private BufferedReader reader = null;
    private StringTokenizer tokenizer = null;

    public FastScanner(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    // Read the next token from the input stream.
    public String next() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    // Read the next line from the input stream.
    public String nextLine() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        return tokenizer.nextToken("\n");
    }

    // Read the next long from the input stream.
    public long nextLong() {
        return Long.parseLong(next());
    }

    // Read the next int from the input stream.
    public int nextInt() {
        return Integer.parseInt(next());
    }

    // Read the next double from the input stream.
    public double nextDouble() {
        return Double.parseDouble(next());
    }

    // Read the next array of ints from the input stream.
    public int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    // Read the next array of longs from the input stream.
    public long[] nextLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = nextLong();
        return a;
    }
}
