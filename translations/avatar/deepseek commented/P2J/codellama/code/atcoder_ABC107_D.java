
import java.util.Scanner;

class BIT {
    private int size;
    private int[] tree;
    private int depth;

    public BIT(int N) {
        this.size = N;
        this.tree = new int[N + 1];
        this.depth = (int) (Math.log(N) / Math.log(2)) + 1;
    }

    private int _bitsum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i ^= i & -i;
        }
        return ret;
    }

    public int bitsum(int l, int r) {
        if (r == 0) {
            return _bitsum(l);
        } else {
            return _bitsum(r) - _bitsum(l);
        }
    }

    public void bitadd(int i, int x) {
        i++;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = n * (n + 1) / 4;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] _a = new int[n + 1];
        int[] d = new int[n + 1];
        for (int i = 0; i < n; i++) {
            _a[i + 1] = a[i];
        }
        for (int i = 0; i < n; i++) {
            d[_a[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            a[i] = d[a[i]];
        }

        boolean check(int X) {
            int[] b = new int[n + 1];
            for (int i = 0; i < n; i++) {
                b[i + 1] = (a[i] >= X) ? 2 : -1;
            }
            for (int i = 1; i <= n; i++) {
                b[i] += b[i - 1];
            }
            int c = Integer.MIN_VALUE;
            for (int i = 1; i <= n; i++) {
                c = Math.max(c, b[i]);
            }
            for (int i = 1; i <= n; i++) {
                b[i] -= c;
            }
            BIT bit = new BIT(c + 1);
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                ans += bit.bitsum(b[i]);
                bit.bitadd(b[i], 1);
            }
            return ans >= m;
        }

        int t[] = new int[2];
        t[0] = n;
        t[1] = 0;
        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            if (check(mid)) {
                t[0] = mid;
            } else {
                t[1] = mid;
            }
        }
        System.out.println(_a[t[1]]);
    }
}

