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

        String nextLine() {
            String line = "";
            try {
                line = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return line;
        }

        char[] nextCharArray() {
            return nextLine().toCharArray();
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        char[] s = sc.nextCharArray();
        char[] t = sc.nextCharArray();

        List<String> ans = new ArrayList<>();
        for (int i = 0; i <= s.length - t.length; i++) {
            boolean f = true;
            char[] ss = s.clone();

            for (int j = 0; j < t.length; j++) {
                if (s[i + j] != t[j] && s[i + j] != '?') {
                    f = false;
                    break;
                } else {
                    ss[i + j] = t[j];
                }
            }
            if (f) {
                ans.add(new String(ss).replace('?', 'a'));
            }
        }
        Collections.sort(ans);
        if (ans.isEmpty()) {
            out.println("UNRESTORABLE");
        } else {
            out.println(ans.get(0));
        }
        out.flush();
    }
}
