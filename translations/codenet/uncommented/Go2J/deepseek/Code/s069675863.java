import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static InputStream inputStream = System.in;
    static OutputStream outputStream = System.out;
    static InputReader in = new InputReader(inputStream);
    static PrintWriter out = new PrintWriter(outputStream);

    static char[] S;
    static int x, y;

    static boolean[][] dpx = new boolean[8000][20000];
    static boolean[][] dpy = new boolean[8000][20000];

    public static void main(String[] args) {
        S = in.next().toCharArray();
        x = in.nextInt();
        y = in.nextInt();

        List<Integer> F = new ArrayList<>();
        int cur = 0;
        for (int i = 0; i < S.length; i++) {
            if (S[i] == 'F') {
                cur++;
            } else {
                F.add(cur);
                cur = 0;
            }
        }
        F.add(cur);

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

        dpx[0][10000] = true;
        dpy[0][10000] = true;
        for (int i = 0; i < evens.length; i++) {
            int val = evens[i];
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpx[i + 1][j + val] |= dpx[i][j];
                }
                if (j - val >= 2000) {
                    dpx[i + 1][j - val] |= dpx[i][j];
                }
            }
        }
        for (int i = 0; i < odds.length; i++) {
            int val = odds[i];
            for (int j = 2000; j <= 18000; j++) {
                if (j + val <= 18000) {
                    dpy[i + 1][j + val] |= dpy[i][j];
                }
                if (j - val >= 2000) {
                    dpy[i + 1][j - val] |= dpy[i][j];
                }
            }
        }

        if (dpx[evens.length][x + 10000] && dpy[odds.length][y + 10000]) {
            out.println("Yes");
        } else {
            out.println("No");
        }
        out.flush();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char[] nextCharArray() {
            return next().toCharArray();
        }
    }
}
