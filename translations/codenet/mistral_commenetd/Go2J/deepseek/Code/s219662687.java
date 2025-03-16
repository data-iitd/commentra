import java.util.*;
import java.io.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        final int INF = (int) Math.pow(10, 11);
        FastScanner scanner = new FastScanner(System.in);

        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int Q = scanner.nextInt();

        int[] s = new int[A + 2];
        s[0] = -INF;
        s[A + 1] = INF;
        for (int i = 1; i <= A; i++) {
            s[i] = scanner.nextInt();
        }

        int[] t = new int[B + 2];
        t[0] = -INF;
        t[B + 1] = INF;
        for (int i = 1; i <= B; i++) {
            t[i] = scanner.nextInt();
        }

        for (int i = 0; i < Q; i++) {
            int x = scanner.nextInt();
            int b = binarySearch(s, x);
            int d = binarySearch(t, x);

            int res = INF;
            for (int S : new int[]{s[b - 1], s[b]}) {
                for (int T : new int[]{t[d - 1], t[d]}) {
                    int d1 = Math.abs(S - x);
                    int d2 = Math.abs(T - S);
                    res = Math.min(res, Math.min(d1, d2));
                }
            }

            System.out.println(res);
        }
    }

    static int binarySearch(int[] arr, int key) {
        int low = 0, high = arr.length - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}
