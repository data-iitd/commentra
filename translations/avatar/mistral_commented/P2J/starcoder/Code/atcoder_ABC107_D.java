
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] d = new int[n];
        int[] _a = new int[n];
        for (int i = 0; i < n; i++) {
            _a[i] = a[i];
        }
        Arrays.sort(_a);
        int[] b = new int[n + 1];
        for (int i = 0; i < n; i++) {
            d[i] = Arrays.binarySearch(_a, a[i]);
            if (d[i] < 0) {
                d[i] = -d[i] - 1;
            }
            b[i + 1] = d[i];
        }
        for (int i = 0; i < n; i++) {
            b[i + 1] += b[i];
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            c += b[i] < 0? 1 : 0;
        }
        for (int i = 0; i < n; i++) {
            b[i] -= c;
        }
        int m = b[n - 1] + 2;
        BIT bit = new BIT(m);
        int ans = 0;
        for (int x : b) {
            ans += bit.bitsum(x + 1);
            bit.bitadd(x, 1);
        }
        System.out.println(ans >= m? _a[b.length - 1] : -1);
    }
}

class BIT {
    int[] tree;
    int size;
    int depth;

    public BIT(int size) {
        this.size = size;
        this.tree = new int[size + 1];
        this.depth = size.bitLength();
    }

    public int _bitsum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i &= i - 1;
        }
        return ret;
    }

    public int bitsum(int l, int r) {
        return _bitsum(r) - _bitsum(l);
    }

    public void bitadd(int i, int x) {
        i++;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }
}

