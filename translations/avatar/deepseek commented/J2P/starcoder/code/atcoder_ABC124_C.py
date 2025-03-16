import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CColoringColorfully solver = new CColoringColorfully();
        solver.solve(1, in, out);
        out.close();
    }

    static class CColoringColorfully {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            // Read the input string
            String x = in.next();
            // Create two StringBuilder objects to manipulate the string
            StringBuilder a = new StringBuilder(x);
            StringBuilder b = new StringBuilder(x);
            // Initialize counters for the number of changes needed
            int a1 = 0;
            int a2 = 0;

            // First loop to change characters to make the string colorful
            for (int i = 1; i < x.length(); i++) {
                if (a.charAt(i) == a.charAt(i - 1)) {
                    // Change the character to the opposite
                    if (a.charAt(i) == '1') {
                        a.setCharAt(i, '0');
                    } else {
                        a.setCharAt(i, '1');
                    }
                    // Increment the counter
                    a1++;
                }
            }

            // Second loop to change characters to make the string colorful
            for (int i = x.length() - 1; i > 0; i--) {
                if (b.charAt(i) == b.charAt(i - 1)) {
                    // Change the character to the opposite
                    if (b.charAt(i - 1) == '1') {
                        b.setCharAt(i - 1, '0');
                    } else {
                        b.setCharAt(i - 1, '1');
                    }
                    // Increment the counter
                    a2++;
                }
            }

            // Output the minimum number of changes needed
            out.println(Math.min(a1, a2));
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null ||!tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
    }
}
