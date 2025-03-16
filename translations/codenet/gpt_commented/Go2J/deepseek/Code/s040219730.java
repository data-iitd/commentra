import java.io.*;
import java.util.*;

public class Main {
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
                s += this.dat[i];
                i -= i & (-i);
            }
            return s;
        }

        public void add(int i, int x) {
            while (i <= this.n) {
                this.dat[i] += x;
                i += i & (-i);
            }
        }

        public int lowerBound(int w) {
            if (w <= 0) {
                return 0;
            }
            int x = 0;
            for (int k = this.minPow2; k > 0; k /= 2) {
                if (x + k <= this.n && this.dat[x + k] < w) {
                    w -= this.dat[x + k];
                    x += k;
                }
            }
            return x + 1;
        }
    }

    static class Query implements Comparable<Query> {
        int idx, l, r;

        public Query(int idx, int l, int r) {
            this.idx = idx;
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Query other) {
            return Integer.compare(this.r, other.r);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        int[] C = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int[] P = new int[500005];
        int[] Answers = new int[500005];
        Arrays.fill(P, -1);

        List<Query> queries = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
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
}
