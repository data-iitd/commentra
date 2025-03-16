import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1000000000 + 7;
    static final int MAX_N = 500000 + 50;

    static int n, q;
    static int[] C = new int[MAX_N];
    static Query[] Q = new Query[MAX_N];
    static int[] P = new int[MAX_N];
    static int[] Answers = new int[MAX_N];

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

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            C[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < q; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            Q[i] = new Query(i, l, r);
        }

        Arrays.sort(Q, Comparator.comparingInt(query -> query.r));
        FenwickTree ft = new FenwickTree(MAX_N);

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

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < q; i++) {
            sb.append(Answers[i]).append("\n");
        }
        System.out.print(sb);
    }

    static class FenwickTree {
        int[] dat;
        int n;

        FenwickTree(int n) {
            this.n = n;
            dat = new int[n + 1];
        }

        int sum(int i) {
            int s = 0;
            while (i > 0) {
                s += dat[i];
                i -= i & (-i);
            }
            return s;
        }

        void add(int i, int x) {
            while (i <= n) {
                dat[i] += x;
                i += i & (-i);
            }
        }
    }
}
