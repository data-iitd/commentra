import java.io.*;
import java.util.*;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    static int[] par, rank;

    public static void main(String[] args) {
        FastReader fr = new FastReader();
        int n = fr.nextInt();
        int m = fr.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = fr.nextInt() - 1;
        }

        initialize(n);

        for (int i = 0; i < m; i++) {
            int x = fr.nextInt() - 1;
            int y = fr.nextInt() - 1;
            unite(x, y);
        }

        int s = 0;
        for (int i = 0; i < n; i++) {
            if (same(i, p[i])) {
                s++;
            }
        }

        System.out.println(s);
    }

    static void initialize(int n) {
        par = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    static int root(int i) {
        if (par[i] == i) {
            return i;
        }
        par[i] = root(par[i]);
        return par[i];
    }

    static boolean same(int i, int j) {
        return root(i) == root(j);
    }

    static void unite(int i, int j) {
        i = root(i);
        j = root(j);
        if (i == j) {
            return;
        }
        if (rank[i] < rank[j]) {
            par[i] = j;
        } else {
            par[j] = i;
            if (rank[i] == rank[j]) {
                rank[i]++;
            }
        }
    }
}
