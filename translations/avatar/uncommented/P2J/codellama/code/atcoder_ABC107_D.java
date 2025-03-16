import java.util.*;

class BIT {
    int size;
    int[] tree;
    int depth;

    public BIT(int N) {
        this.size = N;
        this.tree = new int[N + 1];
        this.depth = (int) (Math.log(N) / Math.log(2)) + 1;
    }

    public int _bitsum(int i) {
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
        int m = n * (n + 1) / 2;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] _a = new int[n + 1];
        int[] d = new int[n + 1];
        for (int i = 0; i < n; i++) {
            _a[i] = a[i];
        }
        Arrays.sort(_a);
        for (int i = 0; i < n; i++) {
            d[_a[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            a[i] = d[a[i]];
        }
        int[] b = new int[n + 1];
        for (int i = 0; i < n; i++) {
            b[i + 1] = (a[i] >= _a[i]) ? 2 : -1;
        }
        for (int i = 0; i < n; i++) {
            b[i + 1] += b[i];
        }
        int c = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            c = Math.max(c, b[i]);
        }
        for (int i = 0; i < n; i++) {
            b[i] -= c;
        }
        BIT bit = new BIT(c + 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += bit.bitsum(b[i] + 1);
            bit.bitadd(b[i], 1);
        }
        if (ans >= m) {
            System.out.println(_a[c]);
        } else {
            System.out.println(_a[c - 1]);
        }
    }
}

