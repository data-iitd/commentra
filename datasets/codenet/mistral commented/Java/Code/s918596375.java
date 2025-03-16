
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.AbstractMap;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		// Initialize FastScanner and PrintWriter objects
		FastScanner sc = new FastScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);

		// Call the solve method to process the input and output the result
		solve(sc,out);

		// Flush the PrintWriter to ensure all output is written to the console
		out.flush();
	}

	public static void solve(FastScanner sc, PrintWriter out) {
		// Read the first string from the input
		String s = sc.next();

		// Define an array of vowels for later comparison
		String[] a = {"a","e","i","o","u"};

		// Iterate through each vowel in the array
		for(String str : a) {
			// Compare the input string to the current vowel
			if(str.equalsIgnoreCase(s)) {
				// If a match is found, print "vowel" and exit the method
				out.println("vowel");
				return;
			}
		}

		// If no vowels were found, print "consonant"
		out.println("consonant");
	}

	// Helper methods for calculating the greatest common divisor (gcd) and least common multiple (lcm)
	public static int gcd(int a, int b) {
		// Recursive method to find the gcd of two integers
		if(a < b) return gcd(b, a);
		if(b == 0) return a;
		return gcd(b, a % b);
	}

	public static long gcd(long a, long b) {
		// Recursive method to find the gcd of two long integers
		if(a < b) return gcd(b, a);
		if(b == 0) return a;
		return gcd(b, a % b);
	}

	public static int lcm(int a, int b) {
		// Calculate the least common multiple of two integers by finding their gcd and multiplying them
		return (a * b) / gcd(a, b);
	}
}

class Pair<K, V> extends AbstractMap.SimpleEntry<K, V> {

    public Pair(final K key, final V value) {
        super(key, value);
    }

    // Method to swap the key-value pair in the Pair object
    public Pair<V, K> swap() {
    	// Create a new Pair object with the swapped key-value pair
    	return new Pair<V, K>(getValue(), getKey());
    }
 }

class FastScanner {
    private BufferedReader reader = null;
    private StringTokenizer tokenizer = null;

    public FastScanner(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

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

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
         return Double.parseDouble(next());
     }

    public int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    public long[] nextLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = nextLong();
        return a;
    }
}