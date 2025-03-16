import java.io.*;
import java.util.*;

public class Main {
    static class Scanner {
        private BufferedReader br;
        private StringTokenizer st;

        public Scanner(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
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

        public char[] nextCharArray() throws IOException {
            return next().toCharArray();
        }

        public String[] nextStringArray(int n) throws IOException {
            String[] arr = new String[n];
            for (int i = 0; i < n; i++) {
                arr[i] = next();
            }
            return arr;
        }

        public int[] nextIntArray(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextInt();
            }
            return arr;
        }

        public long[] nextLongArray(int n) throws IOException {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextLong();
            }
            return arr;
        }

        public double[] nextDoubleArray(int n) throws IOException {
            double[] arr = new double[n];
            for (int i = 0; i < n; i++) {
                arr[i] = nextDouble();
            }
            return arr;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();

        if (N == 0) {
        }

        if (N < 4) {
            System.out.println(0);
            return;
        }

        // Counts the number of 'R', 'B', and 'G' characters in S.
        int nr = 0, nb = 0, ng = 0;
        for (char c : S.toCharArray()) {
            if (c == 'R') {
                nr++;
            }
            if (c == 'B') {
                nb++;
            }
            if (c == 'G') {
                ng++;
            }
        }

        // Calculates the number of triplets where the characters are all different.
        int same = 0;
        for (int a = 1; a < N; a++) {
            int i = 0;
            int j = a;
            int k = 2 * a;
            if (k >= N) {
                break;
            }
            while (k < N) {
                if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
                    same++;
                }
                i++;
                j++;
                k++;
            }
        }

        // Calculates the total number of possible triplets.
        int tot = nr * nb * ng;

        // Prints the difference between the total number of possible triplets and the number of triplets with all different characters.
        System.out.println(tot - same);
    }
}
