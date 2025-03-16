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
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        public FastScanner(InputStream inputStream) {
            reader = new BufferedReader(new InputStreamReader(inputStream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }
    }

    static class FenwickTree {
        private long[] data;
        private int n;
        private int minPow2;

        public FenwickTree(int n) {
            this.data = new long[n + 1];
            this.n = n;

            this.minPow2 = 1;
            while ((this.minPow2 << 1) <= n) {
                this.minPow2 <<= 1;
            }
        }

        public long sum(int i) {
            long s = 0;
            while (i > 0) {
                s += this.data[i];
                i -= i & -i;
            }
            return s;
        }

        public void add(int i, long x) {
            while (i <= this.n) {
                this.data[i] += x;
                i += i & -i;
            }
        }

        public int lowerBound(long w) {
            if (w <= 0) {
                return 0;
            }

            int x = 0;
            for (int k = this.minPow2; k > 0; k /= 2) {
                if (x + k <= this.n && this.data[x + k] < w) {
                    w -= this.data[x + k];
                    x += k;
                }
            }

            return x + 1;
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        int n = scanner.nextInt();
        int q = scanner.nextInt();
        int[] C = new int[n];
        for (int i = 0; i < n; i++) {
            C[i] = scanner.nextInt();
        }

        int[] P = new int[500005];
        long[] Answers = new long[q];
        List<Query> queries = new ArrayList<>();

        for (int i = 0; i < q; i++) {
            int l = scanner.nextInt();
            int r = scanner.nextInt();
            queries.add(new Query(i, l, r));
        }

        Collections.sort(queries, (a, b) -> Integer.compare(a.r, b.r));
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

    static class Query {
        int idx, l, r;

        public Query(int idx, int l, int r) {
            this.idx = idx;
            this.l = l;
            this.r = r;
        }
    }
}
