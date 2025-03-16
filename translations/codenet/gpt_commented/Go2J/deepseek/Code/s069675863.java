import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] nextIntArray(int n) {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] nextLongArray(int n) {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        char[] S = scanner.next().toCharArray();
        int x = scanner.nextInt();
        int y = scanner.nextInt();

        List<Integer> F = new ArrayList<>();
        int current = 0;

        for (char c : S) {
            if (c == 'F') {
                current++;
            } else {
                F.add(current);
                current = 0;
            }
        }
        F.add(current);

        int[] evens = new int[F.size() / 2 + 1];
        int[] odds = new int[F.size() / 2 + 1];
        int evenIndex = 0, oddIndex = 0;

        for (int i = 0; i < F.size(); i++) {
            if (i % 2 == 0) {
                evens[evenIndex++] = F.get(i);
            } else {
                odds[oddIndex++] = F.get(i);
            }
        }

        boolean[][] dpx = new boolean[evens.length + 1][20001];
        boolean[][] dpy = new boolean[odds.length + 1][20001];
        dpx[0][10000] = true;
        dpy[0][10000] = true;

        for (int i = 0; i < evens.length; i++) {
            int val = evens[i];
            for (int j = 0; j <= 20000; j++) {
                if (j + val <= 20000) {
                    dpx[i + 1][j + val] |= dpx[i][j];
                }
                if (j - val >= 0) {
                    dpx[i + 1][j - val] |= dpx[i][j];
                }
            }
        }

        for (int i = 0; i < odds.length; i++) {
            int val = odds[i];
            for (int j = 0; j <= 20000; j++) {
                if (j + val <= 20000) {
                    dpy[i + 1][j + val] |= dpy[i][j];
                }
                if (j - val >= 0) {
                    dpy[i + 1][j - val] |= dpy[i][j];
                }
            }
        }

        if (dpx[evens.length][x + 10000] && dpy[odds.length][y + 10000]) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
