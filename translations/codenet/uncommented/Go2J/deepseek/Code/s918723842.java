import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner();
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();

        int A = Math.max(H, W);

        System.out.println((N + A - 1) / A);
    }

    static int max(int a, int b) {
        return a < b ? b : a;
    }

    static class Scanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        Scanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }

        String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        String nextLine() throws IOException {
            return reader.readLine();
        }

        int[] nextIntArray() throws IOException {
            String[] parts = nextLine().split(" ");
            int[] result = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                result[i] = Integer.parseInt(parts[i]);
            }
            return result;
        }

        long[] nextLongArray() throws IOException {
            String[] parts = nextLine().split(" ");
            long[] result = new long[parts.length];
            for (int i = 0; i < parts.length; i++) {
                result[i] = Long.parseLong(parts[i]);
            }
            return result;
        }

        boolean[] nextBooleanArray() throws IOException {
            String[] parts = nextLine().split(" ");
            boolean[] result = new boolean[parts.length];
            for (int i = 0; i < parts.length; i++) {
                result[i] = Boolean.parseBoolean(parts[i]);
            }
            return result;
        }
    }
}
