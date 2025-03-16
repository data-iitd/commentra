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

    static class FastWriter {
        BufferedWriter bw;

        FastWriter() {
            bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        void print(Object object) {
            try {
                bw.append("" + object);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        void println(Object object) {
            print(object);
            try {
                bw.append("\n");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        void close() {
            try {
                bw.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    static int[] fa = new int[100005];
    static int[] v = new int[200005];

    static int get(int x) {
        if (x == fa[x]) return x;
        int f = get(fa[x]);
        v[x] += v[fa[x]];
        return fa[x] = f;
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner(System.in);
        FastWriter fw = new FastWriter();

        int n = fs.nextInt();
        int m = fs.nextInt();

        for (int i = 1; i <= n; i++) fa[i] = i;

        for (int i = 1; i <= m; i++) {
            int l = fs.nextInt();
            int r = fs.nextInt();
            int vi = fs.nextInt();
            int li = get(l);
            int ri = get(r);

            if (li != ri) {
                v[ri] = vi - v[r] + v[l];
                fa[ri] = li;
            } else {
                if (v[r] - v[l] != vi) {
                    fw.println("No");
                    fw.close();
                    return;
                }
            }
        }

        fw.println("Yes");
        fw.close();
    }
}
