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

        public double[] nextDoubleArray(int n) {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }
    }

    static int a, b, c;
    static int k;

    public static void main(String[] args) {
        a = in.nextInt();
        b = in.nextInt();
        c = in.nextInt();
        k = in.nextInt();

        List<List<Integer>> patterns = duplicatePatterns(new ArrayList<>(), new int[]{0, 1, 2, 3}, k);

        for (List<Integer> P : patterns) {
            int r = a, g = b, B = c;
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 0) {
                    continue;
                } else if (P.get(i) == 1) {
                    r *= 2;
                } else if (P.get(i) == 2) {
                    g *= 2;
                } else if (P.get(i) == 3) {
                    B *= 2;
                }
            }

            if (g > r && B > g) {
                out.println("Yes");
                out.flush();
                return;
            }
        }
        out.println("No");
        out.flush();
    }

    // DuplicatePatterns returns all patterns of n^k of elems(List<Integer>).
    public static List<List<Integer>> duplicatePatterns(List<Integer> pattern, int[] elems, int k) {
        if (pattern.size() == k) {
            List<List<Integer>> result = new ArrayList<>();
            result.add(new ArrayList<>(pattern));
            return result;
        }

        List<List<Integer>> res = new ArrayList<>();
        for (int elem : elems) {
            pattern.add(elem);
            res.addAll(duplicatePatterns(pattern, elems, k));
            pattern.remove(pattern.size() - 1);
        }

        return res;
    }
}
