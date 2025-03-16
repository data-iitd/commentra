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

        public FastScanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
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
            String str = "";
            try {
                str = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int k = scanner.nextInt();

        List<List<Integer>> patterns = generatePatterns(new ArrayList<>(), new int[]{0, 1, 2, 3}, k);

        for (List<Integer> P : patterns) {
            int r = a, g = b, bl = c;
            for (int i = 0; i < P.size(); i++) {
                if (P.get(i) == 1) {
                    r *= 2;
                } else if (P.get(i) == 2) {
                    g *= 2;
                } else if (P.get(i) == 3) {
                    bl *= 2;
                }
            }

            if (g > r && bl > g) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }

    public static List<List<Integer>> generatePatterns(List<Integer> current, int[] elements, int k) {
        if (current.size() == k) {
            List<List<Integer>> result = new ArrayList<>();
            result.add(new ArrayList<>(current));
            return result;
        }

        List<List<Integer>> patterns = new ArrayList<>();
        for (int element : elements) {
            current.add(element);
            patterns.addAll(generatePatterns(current, elements, k));
            current.remove(current.size() - 1);
        }

        return patterns;
    }
}
