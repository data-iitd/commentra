import java.util.*;

public class Main {
    static class Ban {
        long l;
        long r;
        long val;

        Ban(long l_, long r_, long val_) {
            l = l_;
            r = r_;
            val = val_;
        }
    }

    static class SparseTable {
        static final int LIM = 20;
        static final int N = 200007;
        long[][] mn = new long[LIM][N];
        int[] pw = new int[N];

        void init(long[] a) {
            int n = (int) a.length;
            for (int i = 0; i < n; i++) {
                mn[0][i] = a[i];
            }
            for (int i = 0; i + 1 < LIM; i++) {
                for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                    mn[i + 1][j] = Math.max(mn[i][j], mn[i][j + (1 << i)]);
                }
            }
            pw[1] = 0;
            for (int i = 2; i < N; i++) {
                pw[i] = pw[i / 2] + 1;
            }
        }

        long get(int l, int r) {
            r++;
            int p = pw[r - l];
            return Math.min(mn[p][l], mn[p][r - (1 << p)]);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long[] a = new long[(int) n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }
        long[] dl = new long[(int) n];
        for (int i = 0; i < n; i++) {
            if (a[i] > i) {
                System.out.println(-1);
                return;
            }
            dl[i] = i - a[i];
        }
        long ans = 0;
        List<Ban> bans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int r = i;
            while (r + 1 < n && a[r] + 1 == a[r + 1]) {
                r++;
            }
            ans += a[r];
            i = r;
            bans.add(new Ban(r - a[r], r, r - a[r]));
        }
        SparseTable sp = new SparseTable();
        sp.init(dl);
        for (Ban t : bans) {
            if (sp.get((int) t.l, (int) t.r) > t.val) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(ans);
    }
}

// <END-OF-CODE>
