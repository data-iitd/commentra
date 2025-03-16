import java.util.Arrays;
import java.util.Scanner;

public class PrimeCount {
    static final int MAX = 707106;
    static boolean[] tbl = new boolean[MAX + 1];
    static int[] prime = new int[57100];
    static int sz;

    static void sieve() {
        int i, j, k;
        for (i = 1; i < 147; i++) {
            k = prime[i];
            for (j = k * k; j < MAX; j += k) tbl[j] = true;
        }
        for (sz = 146, i = 853; i <= MAX; i += 2) {
            if (!tbl[i]) prime[sz++] = i;
        }
    }

    static int bsch(int x) {
        int l = 0, r = sz, m;
        while (l < r) {
            m = (l + r) >> 1;
            if (prime[m] == x) return m;
            if (prime[m] < x) l = m + 1;
            else r = m;
        }
        return l - 1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long A = scanner.nextLong(), B = scanner.nextLong();
        long a = A - B, b = A + B;
        if (b <= 1) {
            System.out.println(0);
            return;
        }
        if (a <= 1) a = 2;
        sieve();
        int sz = bsch((int) Math.sqrt(b >> 1));
        int[] idx = new int[(int) (b - a + 1)];
        int[] base = new int[(int) (b - a + 1)];
        long[] pp = new long[41];
        Arrays.fill(idx, 1);
        Arrays.fill(base, 0);
        for (int i = 0; i <= sz; i++) {
            int p = prime[i];
            for (int k = 1, j = p; j <= b; j *= p) pp[k++] = j;
            for (; k > 0; k--) {
                long j = pp[k - 1];
                long ll = j * (1 + (a - 1) / j);
                long rr = j * (b / j);
                for (; ll <= rr; ll += j) {
                    int x = (int) (ll - a);
                    if (idx[x] == 1 || base[x] == p) continue;
                    base[x] = p;
                    idx[x] = k;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < idx.length; i++) {
            if (idx[i] != 1) ans++;
        }
        System.out.println(ans);
    }
}
