import java.io.*;
import java.util.*;

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
    }

    public static void reverseSegment(int[] a, int b, int e) {
        for (int i = b; i < (b + e) / 2; i++) {
            int temp = a[i];
            a[i] = a[e - (i - b) - 1];
            a[e - (i - b) - 1] = temp;
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int b = scanner.nextInt();
            int e = scanner.nextInt();
            reverseSegment(a, b, e);
        }
        PrintWriter out = new PrintWriter(System.out);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                out.print(" ");
            }
            out.print(a[i]);
        }
        out.println();
        out.flush();
    }
}
