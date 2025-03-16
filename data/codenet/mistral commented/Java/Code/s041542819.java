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
 * Main class for the solution of problem Main.
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        // Initialize input and output streams, scanner, and solver
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        LightScanner in = new LightScanner(inputStream);
        LightWriter out = new LightWriter(outputStream);
        DLazyFaith solver = new DLazyFaith();

        // Solve the problem with given test number, input, and output
        solver.solve(1, in, out);

        // Close the output stream
        out.close();
    }

    static class DLazyFaith {
        public void solve(int testNumber, LightScanner in, LightWriter out) {
            // Read input parameters: a, b, and q
            int a = in.ints();
            int b = in.ints();
            int q = in.ints();

            // Initialize long arrays s and t
            long[] s = new long[a + 2];
            long[] t = new long[b + 2];

            // Initialize s[0] and t[0] with large negative values
            s[0] = t[0] = -10_000_000_000L;

            // Read elements of array s
            for (int i = 0; i < a; i++) {
                s[i + 1] = in.longs();
            }

            // Read elements of array t
            for (int i = 0; i < b; i++) {
                t[i + 1] = in.longs();
            }

            // Initialize s[a+1] and t[b+1] with large positive values
            s[a + 1] = t[b + 1] = 20_000_000_000L;

            // Process each query
            for (int i = 0; i < q; i++) {
                long x = in.longs();
                long sl = x - s[Math.max(0, ArrayUtil.lowerBound(s, x + 1) - 1)];
                long tl = x - t[Math.max(0, ArrayUtil.lowerBound(t, x + 1) - 1)];
                long sr = s[ArrayUtil.lowerBound(s, x)] - x;
                long tr = t[ArrayUtil.lowerBound(t, x)] - x;

                // Calculate the minimum of six possible answers
                long answer = IntMath.min(
                        Math.max(sl, tl),
                        Math.max(sr, tr),
                        2 * sl + tr,
                        2 * tl + sr,
                        sl + 2 * tr,
                        tl + 2 * sr
                );

                // Write the answer to the output
                out.ansln(answer);
            }
        }

    }

    static class LightScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public LightScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public String string() {
            // Read a line from the input and return it as a string
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    String line = reader.readLine();
                    if (line == null) {
                        throw new NoSuchElementException();
                    }
                    tokenizer = new StringTokenizer(line);
                } catch (IOException e) {
                    throw new UncheckedIOException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int ints() {
            return Integer.parseInt(string());
        }

        public long longs() {
            return Long.parseLong(string());
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
            this(new BufferedWriter(new OutputStreamWriter(out, Charset.defaultCharset())));
        }

        public LightWriter print(char c) {
            try {
                out.write(c);
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter print(String s) {
            try {
                out.write(s, 0, s.length());
                breaked = false;
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
            return this;
        }

        public LightWriter ans(String s) {
            if (!breaked) {
                print(' ');
            }
            return print(s);
        }

        public LightWriter ans(long l) {
            return ans(Long.toString(l));
        }

        public LightWriter ansln(long... n) {
            for (long n1 : n) {
                ans(n1).ln();
            }
            return this;
        }

        public LightWriter ln() {
            print(System.lineSeparator());
            breaked = true;
            if (autoflush) {
                try {
                    out.flush();
                } catch (IOException ex) {
                    throw new UncheckedIOException(ex);
                }
            }
            return this;
        }

        public void close() {
            try {
                out.close();
            } catch (IOException ex) {
                throw new UncheckedIOException(ex);
            }
        }

    }

    static final class IntMath {
        private IntMath() {
        }

        public static long min(long... v) {
            return Arrays.stream(v).min().orElseThrow(NoSuchElementException::new);
        }

    }

    static final class ArrayUtil {
        private ArrayUtil() {
        }

        public static int lowerBound(long[] a, long t, int min) {
            int max = a.length;
            while (min < max) {
                int mid = (min + max) / 2;
                if (t <= a[mid]) {
                    max = mid;
                } else {
                    min = mid + 1;
                }
            }
            return min;
        }

    }
}