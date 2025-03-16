import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.stream.LongStream;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.UncheckedIOException;
import java.util.OptionalLong;
import java.nio.charset.Charset;
import java.util.StringTokenizer;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.util.NoSuchElementException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) { // Entry point of the program
        InputStream inputStream = System.in; // Standard input stream
        OutputStream outputStream = System.out; // Standard output stream
        LightScanner in = new LightScanner(inputStream); // Scanner to read input
        LightWriter out = new LightWriter(outputStream); // Writer to write output
        DLazyFaith solver = new DLazyFaith(); // Create an instance of the solver class
        solver.solve(1, in, out); // Solve the problem with the given input and output
        out.close(); // Close the output writer
    }

    static class DLazyFaith {
        public void solve(int testNumber, LightScanner in, LightWriter out) { // Solve method to process input and produce output
            int a = in.ints(), b = in.ints(), q = in.ints(); // Read the number of temples, shrines, and queries
            long[] s = new long[a + 2], t = new long[b + 2]; // Initialize arrays for temples and shrines with extra space
            s[0] = t[0] = -10_000_000_000L; // Set the first element to a very small value
            for (int i = 0; i < a; i++) {
                s[i + 1] = in.longs(); // Read the temples
            }
            for (int i = 0; i < b; i++) {
                t[i + 1] = in.longs(); // Read the shrines
            }
            s[a + 1] = t[b + 1] = 20_000_000_000L; // Set the last element to a very large value
            for (int i = 0; i < q; i++) {
                long x = in.longs(); // Read the query
                long sl = x - s[Math.max(0, ArrayUtil.lowerBound(s, x + 1) - 1)]; // Calculate the distance to the nearest temple (left)
                long tl = x - t[Math.max(0, ArrayUtil.lowerBound(t, x + 1) - 1)]; // Calculate the distance to the nearest shrine (left)
                long sr = s[ArrayUtil.lowerBound(s, x)] - x; // Calculate the distance to the nearest temple (right)
                long tr = t[ArrayUtil.lowerBound(t, x)] - x; // Calculate the distance to the nearest shrine (right)
                out.ansln(IntMath.min( // Print the minimum distance among the possible options
                        Math.max(sl, tl),
                        Math.max(sr, tr),
                        2 * sl + tr,
                        2 * tl + sr,
                        sl + 2 * tr,
                        tl + 2 * sr
                ));
            }
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in)); // Initialize BufferedReader with InputStream
        }

        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine()); // Read a line and tokenize it
                } catch (IOException e) {
                    throw new UncheckedIOException(e); // Throw an unchecked exception if an I/O error occurs
                }
            }
            return tokenizer.nextToken(); // Return the next token
        }

        public int ints() {
            return Integer.parseInt(string()); // Parse the next token as an integer
        }

        public long longs() {
            return Long.parseLong(string()); // Parse the next token as a long integer
        }

    }

    static class LightWriter implements AutoCloseable {
        private final Writer out;
        private boolean autoflush = false;
        private boolean breaked = true;

        public LightWriter(Writer out) {
            this.out = out;
        }

        public LightWriter(OutputStream out) {
            this(new BufferedWriter(new OutputStreamWriter(out, Charset.defaultCharset()))); // Initialize BufferedWriter with OutputStream
        }

        public LightWriter print(char c) {
            try {
                out.write(c); // Write a character
                breaked = false; // Mark that a character was written
            } catch (IOException ex) {
                throw new UncheckedIOException(ex); // Throw an unchecked exception if an I/O error occurs
            }
            return this; // Return the LightWriter instance for method chaining
        }

        public LightWriter print(String s) {
            try {
                out.write(s, 0, s.length()); // Write a string
                breaked = false; // Mark that a character was written
            } catch (IOException ex) {
                throw new UncheckedIOException(ex); // Throw an unchecked exception if an I/O error occurs
            }
            return this; // Return the LightWriter instance for method chaining
        }

        public LightWriter ans(String s) {
            if (!breaked) {
                print(' '); // Print a space if necessary
            }
            return print(s); // Print the string
        }

        public LightWriter ans(long l) {
            return ans(Long.toString(l)); // Print the long integer as a string
        }

        public LightWriter ansln(long... n) {
            for (long n1 : n) {
                ans(n1).ln(); // Print each long integer followed by a line break
            }
            return this; // Return the LightWriter instance for method chaining
        }

        public LightWriter ln() {
            print(System.lineSeparator()); // Print a line separator
            breaked = true; // Mark that a line break was printed
            if (autoflush) {
                try {
                    out.flush(); // Flush the writer if autoflush is enabled
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex); // Throw an unchecked exception if an I/O error occurs
                }
            }
            return this; // Return the LightWriter instance for method chaining
        }

        public void close() {
            try {
                out.close(); // Close the writer
            } catch (IOException ex) {
                throw new UncheckedIOException(ex); // Throw an unchecked exception if an I/O error occurs
            }
        }

    }

    static final class IntMath {
        private IntMath() {
        }

        public static long min(long... v) {
            return Arrays.stream(v).min().orElseThrow(NoSuchElementException::new); // Return the minimum value among the provided long integers
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static int lowerBound(long[] a, long t) {
            return lowerBound(a, t, 0); // Call the overloaded lowerBound method starting from index 0
        }

        public static int lowerBound(long[] a, long t, int min) {
            int max = a.length;
            while (min < max) {
                int mid = (min + max) / 2;
                if (t <= a[mid]) {
                    max = mid; // Adjust the upper bound
                } else {
                    min = mid + 1; // Adjust the lower bound
                }
            }
            return min; // Return the index where the target should be inserted to maintain sorted order
        }

    }
}
