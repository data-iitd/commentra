import java.util.*;

class BIT {
    private int size;
    private long[] tree;

    public BIT(int N) {
        this.size = N;
        this.tree = new long[N + 1];
    }

    private long bitsum(int i) {
        long ret = 0;
        while (i > 0) {
            ret += tree[i];
            i ^= i & -i;
        }
        return ret;
    }

    public long bitsum(int l, Integer r) {
        if (r == null) {
            return bitsum(l);
        } else {
            return bitsum(r) - bitsum(l);
        }
    }

    public void bitadd(int i, long x) {
        i += 1;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long m = n * (n + 1) / 4;
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextLong();
        }
        Map<Long, Integer> d = new HashMap<>();
        TreeSet<Long> _aSet = new TreeSet<>(Arrays.asList(a));
        _aSet.add(0L);
        List<Long> _a = new ArrayList<>(_aSet);
        for (int i = 0; i < _a.size(); i++) {
            d.put(_a.get(i), i);
        }
        for (int i = 0; i < n; i++) {
            a[i] = d.get(a[i]);
        }

        boolean check(long X) {
            long[] b = new long[n + 1];
            for (int i = 0; i < n; i++) {
                b[i + 1] = b[i] + ((a[i] >= X) ? 1 : -1);
            }
            long c = Long.MAX_VALUE;
            for (long value : b) {
                c = Math.min(c, value);
            }
            for (int i = 0; i < b.length; i++) {
                b[i] -= c;
            }
            BIT bit = new BIT((int) (Arrays.stream(b).max().orElse(0) + 2));
            long ans = 0;
            for (long x : b) {
                ans += bit.bitsum((int) (x + 1));
                bit.bitadd((int) x, 1);
            }
            return ans >= m;
        }

        int[] t = { _a.size(), 0 };
        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            if (check(_a.get(mid))) {
                t[1] = mid;
            } else {
                t[0] = mid;
            }
        }
        System.out.println(_a.get(t[1]));
        scanner.close();
    }
}
//<END-OF-CODE>
