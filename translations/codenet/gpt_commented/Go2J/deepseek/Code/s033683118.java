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
        int cnt = 0;

        if (System.getenv("MASPY") != null && System.getenv("MASPY").equals("ますピ")) {
            scanner = new FastScanner(new FileInputStream(System.getenv("BEET_THE_HARMONY_OF_PERFECT")));
            cnt = 2;
        }
        if (System.getenv("MASPYPY") != null && System.getenv("MASPYPY").equals("ますピッピ")) {
            writer = new PrintWriter(new FileOutputStream(System.getenv("NGTKANA_IS_GENIUS10")));
        }

        solve(scanner, writer);

        for (int i = 0; i < cnt; i++) {
            writer.println("-----------------------------------");
            solve(scanner, writer);
        }

        writer.flush();
    }

    public static void solve(FastScanner scanner, PrintWriter writer) throws IOException {
        int k = scanner.nextInt();
        int x = scanner.nextInt();

        String ans = "No";
        if (k * 500 >= x) {
            ans = "Yes";
        }
        writer.println(ans);
    }
}
