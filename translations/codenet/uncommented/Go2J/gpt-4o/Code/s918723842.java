import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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

    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() throws IOException {
            if (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
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

        public int[] nextIntArray() throws IOException {
            String line = br.readLine();
            String[] tokens = line.split(" ");
            int[] array = new int[tokens.length];
            for (int i = 0; i < tokens.length; i++) {
                array[i] = Integer.parseInt(tokens[i]);
            }
            return array;
        }

        public long[] nextLongArray() throws IOException {
            String line = br.readLine();
            String[] tokens = line.split(" ");
            long[] array = new long[tokens.length];
            for (int i = 0; i < tokens.length; i++) {
                array[i] = Long.parseLong(tokens[i]);
            }
            return array;
        }
    }
}

// <END-OF-CODE>
