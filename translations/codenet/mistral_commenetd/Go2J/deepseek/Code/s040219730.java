import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer tok = new StringTokenizer("");

    static int[] P = new int[500005];
    static int[] Answers = new int[500005];

    static class Query implements Comparable<Query> {
        int idx, l, r;

        public Query(int idx, int l, int r) {
            this.idx = idx;
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Query o) {
            return Integer.compare(this.r, o.r);
        }
    }

    public static void main(String[] args) throws Exception {
        int n = nextInt();
        int q = nextInt();
        int[] C = new int[n];
        for (int i = 0; i < n; i++) {
            C[i] = nextInt();
        }

        List<Query> queries = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int l = nextInt();
            int r = nextInt();
            queries.add(new Query(i, l, r));
        }

        Collections.sort(queries);
        FenwickTree ft = new FenwickTree(500005);

        int k = 0;
        for (Query query : queries) {
            while (k < query.r) {
                if (P[C[k]] != -1) {
                    ft.add(P[C[k]] + 1, -1);
                }
                P[C[k]] = k;
                ft.add(k + 1, 1);
                k++;
            }

            Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
        }

        for (int i = 0; i < q; i++) {
            out.println(Answers[i]);
        }
        out.flush();
    }

    static class FenwickTree {
        private int[] dat;
        private int n;
        private int minPow2;

        public FenwickTree(int n) {
            this.dat = new int[n + 1];
            this.n = n;

            this.minPow2 = 1;
            while ((this.minPow2 << 1) <= n) {
                this.minPow2 <<= 1;
            }
        }

        public int sum(int i) {
            int s = 0;
            while (i > 0) {
                s += dat[i];
                i -= i & (-i);
            }
            return s;
        }

        public void add(int i, int x) {
            while (i <= n) {
                dat[i] += x;
                i += i & (-i);
            }
        }
    }

    static String next() throws Exception {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    static int nextInt() throws Exception {
        return Integer.parseInt(next());
    }

    static long nextLong() throws Exception {
        return Long.parseLong(next());
    }

    static double nextDouble() throws Exception {
        return Double.parseDouble(next());
    }

    static int[] nextIntArray(int n) throws Exception {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    static long[] nextLongArray(int n) throws Exception {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextLong();
        }
        return res;
    }

    static double[] nextDoubleArray(int n) throws Exception {
        double[] res = new double[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextDouble();
        }
        return res;
    }
}
