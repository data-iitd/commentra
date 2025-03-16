import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1000000000 + 7;
    static final int INF_INT64 = Long.MAX_VALUE;
    static final int INF_INT32 = Integer.MAX_VALUE;

    static int n, q;
    static int[] C;
    static Query[] Q;
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

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        C = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            C[i] = Integer.parseInt(st.nextToken());
        }

        // Initialize P array
        Arrays.fill(P, -1);

        // Process queries
        Q = new Query[q];
        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            Q[i] = new Query(i, l, r);
        }

        Arrays.sort(Q, Comparator.comparingInt(query -> query.r));
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

            // Calculate answer
            Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
        }

        // Print answers
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            sb.append(Answers[i]).append("\n");
        }
        System.out.print(sb);
    }

    static class FenwickTree {
        int[] dat;
        int n;
        int minPow2;

        FenwickTree(int n) {
            this.dat = new int[n + 1];
            this.n = n;

            minPow2 = 1;
            while ((minPow2 << 1) <= n) {
                minPow2 <<= 1;
            }
        }

        // Sum of [1, i](1-based)
        int sum(int i) {
            int s = 0;
            while (i > 0) {
                s += dat[i];
                i -= i & (-i);
            }
            return s;
        }

        // Add x to i(1-based)
        void add(int i, int x) {
            while (i <= n) {
                dat[i] += x;
                i += i & (-i);
            }
        }

        // LowerBound returns minimum i such that bit.Sum(i) >= w.
        int lowerBound(int w) {
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
}
// <END-OF-CODE>
