
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    // 入力を読み込むためのクラス
    public static class InputReader {
        private final BufferedReader br;
        private StringTokenizer st;

        public InputReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
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
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    // 出力を行うためのクラス
    public static class OutputWriter {
        private final PrintWriter pw;

        public OutputWriter() {
            pw = new PrintWriter(System.out);
        }

        public void print(Object object) {
            pw.print(object);
        }

        public void println(Object object) {
            pw.println(object);
        }

        public void flush() {
            pw.flush();
        }

        public void close() {
            pw.close();
        }
    }

    // クエリを表すクラス
    public static class Query {
        int idx;
        int l;
        int r;

        public Query(int idx, int l, int r) {
            this.idx = idx;
            this.l = l;
            this.r = r;
        }
    }

    // クエリを処理するためのクラス
    public static class QueryProcessor {
        private final int n;
        private final int q;
        private final int[] C;
        private final List<Query> Q;
        private final int[] P;
        private final int[] answers;

        public QueryProcessor(int n, int q, int[] C) {
            this.n = n;
            this.q = q;
            this.C = C;
            this.Q = new ArrayList<>();
            this.P = new int[n];
            this.answers = new int[q];

            for (int i = 0; i < n; i++) {
                P[i] = -1;
            }

            for (int i = 0; i < q; i++) {
                int l = in.nextInt();
                int r = in.nextInt();
                Query query = new Query(i, l, r);
                Q.add(query);
            }

            Q.sort((a, b) -> {
                return a.r - b.r;
            });

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

                answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
            }
        }

        public void printAnswers() {
            for (int i = 0; i < q; i++) {
                out.println(answers[i]);
            }
        }

        // フェンウィック木
        public static class FenwickTree {
            private final int[] dat;
            private final int n;
            private final int minPow2;

            public FenwickTree(int n) {
                this.dat = new int[n + 1];
                this.n = n;

                this.minPow2 = 1;
                while ((minPow2 << 1) <= n) {
                    minPow2 <<= 1;
                }
            }

            public int sum(int i) {
                int s = 0;

                for (; i > 0; i -= i & -i) {
                    s += dat[i];
                }

                return s;
            }

            public void add(int i, int x) {
                for (; i <= n; i += i & -i) {
                    dat[i] += x;
                }
            }

            public int lowerBound(int w) {
                if (w <= 0) {
                    return 0;
                }

                int x = 0;
                for (int k = minPow2; k > 0; k /= 2) {
                    if (x + k <= n && dat[x + k] < w) {
                        w -= dat[x + k];
                        x += k;
                    }
                }

                return x + 1;
            }
        }

        private final FenwickTree ft = new FenwickTree(500000 + 50);
    }

    public static void main(String[] args) {
        // 入出力を初期化
        in = new InputReader();
        out = new OutputWriter();

        // 入力を受け取る
        int n = in.nextInt();
        int q = in.nextInt();
        int[] C = new int[n];
        for (int i = 0; i < n; i++) {
            C[i] = in.nextInt();
        }

        // クエリを処理する
        QueryProcessor qp = new QueryProcessor(n, q, C);
        qp.printAnswers();

        // 出力を書き込む
        out.flush();
    }

    // 入力を読み込むためのクラス
    public static InputReader in;

    // 出力を行うためのクラス
    public static OutputWriter out;
}

