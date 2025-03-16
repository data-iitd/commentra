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

        FastScanner(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(s));
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
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        if (args.length > 0) {
            scanner = new FastScanner(args[0]);
        }

        PrintWriter out = new PrintWriter(System.out);

        int n = scanner.nextInt();
        int[] aa = new int[n + 2];
        int sum = 0;

        aa[0] = scanner.nextInt();
        for (int i = 1; i <= n; i++) {
            aa[i] = scanner.nextInt();
            sum += Math.abs(aa[i] - aa[i - 1]);
        }
        aa[n + 1] = scanner.nextInt();
        sum += Math.abs(aa[n + 1] - aa[n]);

        for (int i = 1; i <= n; i++) {
            int ans = sum - Math.abs(aa[i] - aa[i - 1]) - Math.abs(aa[i + 1] - aa[i]) + Math.abs(aa[i + 1] - aa[i - 1]);
            out.println(ans);
        }

        out.flush();
    }
}
