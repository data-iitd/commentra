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
    public static void main(String[] args) {
        // Initialize input and output streams
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        
        // Create scanner for input and writer for output
        LightScanner in = new LightScanner(inputStream);
        LightWriter out = new LightWriter(outputStream);
        
        // Create an instance of the solver and execute the solution
        DLazyFaith solver = new DLazyFaith();
        solver.solve(1, in, out);
        
        // Close the output writer
        out.close();
    }

    static class DLazyFaith {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            // Read input values for a, b, and q
            int a = in.ints(), b = in.ints(), q = in.ints();
            
            // Initialize arrays to store positions with boundary values
            long[] s = new long[a + 2], t = new long[b + 2];
            s[0] = t[0] = -10_000_000_000L; // Set lower boundary
            for (int i = 0; i < a; i++) {
                s[i + 1] = in.longs(); // Read positions for array s
            }
            for (int i = 0; i < b; i++) {
                t[i + 1] = in.longs(); // Read positions for array t
            }
            s[a + 1] = t[b + 1] = 20_000_000_000L; // Set upper boundary
            
            // Process each query
            for (int i = 0; i < q; i++) {
                long x = in.longs(); // Read the query value
                
                // Calculate distances to the nearest positions in arrays s and t
                long sl = x - s[Math.max(0, ArrayUtil.lowerBound(s, x + 1) - 1)];
                long tl = x - t[Math.max(0, ArrayUtil.lowerBound(t, x + 1) - 1)];
                long sr = s[ArrayUtil.lowerBound(s, x)] - x;
                long tr = t[ArrayUtil.lowerBound(t, x)] - x;
                
                // Compute the minimum distance using various combinations
                out.ansln(IntMath.min(
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
        private BufferedReader reader = null; // Buffered reader for input
        private StringTokenizer tokenizer = null; // Tokenizer for parsing input

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in)); // Initialize reader
        }

        // Read the next string token
        public String string() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine()); // Read a new line
                } catch (IOException e) {
                    throw new UncheckedIOException(e); // Handle IO exceptions
                }
            }
            return tokenizer.nextToken(); // Return the next token
        }

        // Read the next integer
        public int ints() {
            return Integer.parseInt(string()); // Parse and return as integer
        }

        // Read the next long
        public long longs() {
            return Long.parseLong(string()); // Parse and return as long
        }
    }

    static class LightWriter implements AutoCloseable {
        private final Writer out; // Writer for output
        private boolean autoflush = false; // Autoflush flag
        private boolean breaked = true; // Line break flag

        public LightWriter(Writer out) {
            this.out = out; // Initialize writer
        }

        public LightWriter(OutputStream out) {
            this(new BufferedWriter(new OutputStreamWriter(out, Charset.defaultCharset()))); // Initialize with default charset
        }

        // Print a character
        public LightWriter print(char c) {
            try {
                out.write(c); // Write character to output
                breaked = false; // Reset break flag
            } catch (IOException ex) {
                throw new UncheckedIOException(ex); // Handle IO exceptions
            }
            return this;
        }

        // Print a string
        public LightWriter print(String s) {
            try {
                out.write(s, 0, s.length()); // Write string to output
                breaked = false; // Reset break flag
            } catch (IOException ex) {
                throw new UncheckedIOException(ex); // Handle IO exceptions
            }
            return this;
        }

        // Print a string with a space before it
        public LightWriter ans(String s) {
            if (!breaked) {
                print(' '); // Print space if not at the beginning of a line
            }
            return print(s); // Print the string
        }

        // Print a long value
        public LightWriter ans(long l) {
            return ans(Long.toString(l)); // Convert long to string and print
        }

        // Print multiple long values, each on a new line
        public LightWriter ansln(long... n) {
            for (long n1 : n) {
                ans(n1).ln(); // Print each long value followed by a line break
            }
            return this;
        }

        // Print a line break
        public LightWriter ln() {
            print(System.lineSeparator()); // Print system line separator
            breaked = true; // Set break flag
            if (autoflush) {
                try {
                    out.flush(); // Flush output if autoflush is enabled
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex); // Handle IO exceptions
                }
            }
            return this;
        }

        // Close the writer
        public void close() {
            try {
                out.close(); // Close the output writer
            } catch (IOException ex) {
                throw new UncheckedIOException(ex); // Handle IO exceptions
            }
        }
    }

    static final class IntMath {
        private IntMath() {
        }

        // Return the minimum value from a list of long values
        public static long min(long... v) {
            return Arrays.stream(v).min().orElseThrow(NoSuchElementException::new); // Find and return the minimum
        }
    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        // Find the lower bound index of a value in a sorted array
        public static int lowerBound(long[] a, long t) {
            return lowerBound(a, t, 0); // Call overloaded method with min index 0
        }

        // Find the lower bound index of a value in a sorted array with specified minimum index
        public static int lowerBound(long[] a, long t, int min) {
            int max = a.length; // Set maximum index
            while (min < max) {
                int mid = (min + max) / 2; // Calculate mid index
                if (t <= a[mid]) {
                    max = mid; // Move max to mid if target is less than or equal
                } else {
                    min = mid + 1; // Move min to mid + 1 otherwise
                }
            }
            return min; // Return the lower bound index
        }
    }
}
