
import java.io.*;
import java.util.*;

public class s716019902{
    static final int MOD = 998244353;
    static final int FAC_NUM = 300001;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int sum = 0;

        for (int i = 1; i <= N; i++) {
            if (i % 3 == 0 || i % 5 == 0) {
                continue; // Skip numbers divisible by 3 or 5
            }
            sum += i; // Add the number to the sum
        }

        System.out.println(sum);
    }

    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            eat("");
        }

        private void eat(String s) {
            st = new StringTokenizer(s);
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public boolean hasNextLine() throws IOException {
            return br.ready();
        }

        public String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String s = br.readLine();
                if (s == null) return null;
                eat(s);
            }
            return st.nextToken();
        }

        public boolean hasNext() throws IOException {
            while (!st.hasMoreTokens()) {
                String s = br.readLine();
                if (s == null) return false;
                eat(s);
            }
            return true;
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
    }
}

