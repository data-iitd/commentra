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
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int k = scanner.nextInt();

        List<List<Integer>> patterns = generatePatterns(new ArrayList<>(), new int[]{0, 1, 2, 3}, k);

        for (List<Integer> pattern : patterns) {
            int r = a, g = b, bb = c;
            for (int bit : pattern) {
                if (bit == 1) {
                    r *= 2;
                } else if (bit == 2) {
                    g *= 2;
                } else if (bit == 3) {
                    bb *= 2;
                }
            }

            if (g > r && bb > g) {
                System.out.println("Yes");
                return;
            }
        }

        System.out.println("No");
    }

    private static List<List<Integer>> generatePatterns(List<Integer> current, int[] elements, int k) {
        List<List<Integer>> result = new ArrayList<>();
        if (current.size() == k) {
            result.add(new ArrayList<>(current));
            return result;
        }

        for (int element : elements) {
            current.add(element);
            result.addAll(generatePatterns(current, elements, k));
            current.remove(current.size() - 1);
        }

        return result;
    }
}
