import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (Exception e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        String str = "";
        int[] memo = new int[26];

        while ((str = sc.nextLine()) != null && !str.isEmpty()) {
            for (char c : str.toCharArray()) {
                if (Character.isLowerCase(c)) {
                    memo[c - 'a']++;
                } else if (Character.isUpperCase(c)) {
                    memo[c - 'A']++;
                }
            }
        }

        for (int i = 0; i < 26; i++) {
            out.println((char) (i + 'a') + " : " + memo[i]);
        }

        out.close();
    }
}
