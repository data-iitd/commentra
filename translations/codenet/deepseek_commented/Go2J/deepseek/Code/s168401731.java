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

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        int n = scanner.nextInt();
        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (a % 2 == 1) {
                ans = "first";
                break;
            }
        }
        writer.println(ans);
        writer.flush();
    }
}
