import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
            tokenizer = null;
        }

        public String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        int k = scanner.nextInt();
        int x = scanner.nextInt();

        String ans = "No";

        if (k * 500 >= x) {
            ans = "Yes";
        }

        writer.println(ans);
        writer.flush();
    }
}
