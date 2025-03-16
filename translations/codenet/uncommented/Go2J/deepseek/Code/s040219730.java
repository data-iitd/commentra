import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static class FastScanner {
        private BufferedReader reader = null;
        private StringTokenizer tokenizer = null;

        public FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        public String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }

    static class FastWriter {
        PrintWriter writer;

        FastWriter(OutputStream out) {
            writer = new PrintWriter(out);
        }

        void print(Object object) {
            writer.print(object);
        }

        void println(Object object) {
            writer.println(object);
        }

        void close() {
            writer.close();
        }

        void flush() {
            writer.flush();
        }
    }

    static final int MOD = 1000000000 + 7;
    static final int ALPHABET_NUM = 26;
    static final long INF_INT64 = Long.MAX_VALUE;
    static final int INF_BIT60 = 1 << 60;
    static final int INF_INT32 = Integer.MAX_VALUE;
    static final int INF_BIT30 = 1 << 30;
    static final int NIL = -1;

    static int n, q;
    static int[] C;
    static List<Query> Q = new ArrayList<>();

    static int[] P = new int[500000 + 50];
    static int[] Answers = new int[500000 + 50];

    static class Query {
        int idx, l, r;

        Query(int idx, int l, int r) {
            this.idx = idx;
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        FastWriter out = new FastWriter(System.out);

        n = sc.nextInt();
        q = sc.nextInt();
        C = sc.nextIntArray(n);

        for (int i = 1; i <= n; i++) {
            P[i] = -1;
        }

        for (int i = 0; i < q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            Q.add(new Query(i, l, r));
        }

        Collections.sort(Q, (a, b) -> Integer.compare(a.r, b.r));
        FenwickTree ft = new FenwickTree(500000 + 50);

        int k = 0;
        for (Query query : Q) {
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
        out.close();
    }

    static class FenwickTree {
        int[] dat;
        int n;
        int minPow2;

        FenwickTree(int n) {
            this.dat = new int[n + 1];
            this.n = n;

            this.minPow2 = 1;
            while ((minPow2 << 1) <= n) {
                minPow2 <<= 1;
            }
        }

        void add(int i, int x) {
            while (i <= n) {
                dat[i] += x;
                i += i & -i;
            }
        }

        int sum(int i) {
            int s = 0;
            while (i > 0) {
                s += dat[i];
                i -= i & -i;
            }
            return s;
        }
    }
}
