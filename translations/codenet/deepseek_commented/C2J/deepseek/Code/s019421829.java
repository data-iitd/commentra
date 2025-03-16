import java.util.*;

public class FoxNumber {
    static final int MAX = 707106;
    static boolean[] tbl = new boolean[MAX + 1];
    static int[] prime = new int[57100];
    static int[] sqp = new int[147];
    static int sz;

    static void sieve() {
        int i, j, k;

        for (i = 1; i < 147; i++) {
            k = prime[i];
            for (j = sqp[i]; j < MAX; j += k) tbl[j] = true;
        }
        for (sz = 146, i = 853; i <= MAX; i += 2) if (!tbl[i]) prime[sz++] = i;
    }

    static int[] base = new int[1000002];
    static int[] idx = new int[1000002];
    static long[] pp = new long[41];

    static int bsch(int x) {
        int m, l = 0, r = sz;

        while (l < r) {
            m = (l + r) >> 1;
            if (prime[m] == x) return m;
            if (prime[m] < x) l = m + 1; else r = m;
        }
        return l - 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong(), B = scanner.nextLong();
        long a = A - B, b = A + B;
        if (b <= 1) {
            System.out.println("0");
            return;
        }
        if (a <= 1) a = 2;

        sz = bsch((int) Math.sqrt((double) (b >> 1)));

        Arrays.fill(idx, 1);
        for (int i = 0; i <= sz; i++) {
            int p = prime[i];
            for (int k = 1, j = p; j <= b; j *= p) pp[k++] = j;
            while (--k > 0) {
                j = pp[k];
                long ll = j * (1 + (a - 1) / j);
                long rr = j * (b / j);
                for (; ll <= rr; ll += j) {
                    int x = (int) (ll - a);
                    if (idx[x] == 0 || base[x] == p) continue;
                    if (idx[x] < k) idx[x] = 0;
                    else base[x] = p;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < b - a + 1; i++) {
            if (idx[i] != 0) ans++;
        }
        System.out.println(ans);
    }
}
