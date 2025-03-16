import java.util.*;

class BIT {
    private int size;
    private int[] tree;
    private int depth;

    public BIT(int N) {
        this.size = N;
        this.tree = new int[N + 1];
        this.depth = Integer.toBinaryString(N).length();
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
        return _bitsum(r) - _bitsum(l - 1);
    }

    public void bitadd(int i, int x) {
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
        int m = n * (n + 1) / 4;
        int[] a = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        Map<Integer, Integer> d = new HashMap<>();
        Set<Integer> uniqueValues = new HashSet<>(Arrays.asList(0));
        for (int x : a) {
            uniqueValues.add(x);
        }
        List<Integer> _a = new ArrayList<>(uniqueValues);
        _a.sort(Integer::compareTo);
        for (int i = 0; i < _a.size(); i++) {
            d.put(_a.get(i), i);
        }
        for (int i = 0; i < n; i++) {
            a[i] = d.get(a[i]);
        }

        int[] t = {_a.size(), 0};

        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            if (check(mid, a, n, m)) {
                t[0] = mid;
            } else {
                t[1] = mid;
            }
        }
        System.out.println(_a.get(t[1]));
    }

    public static boolean check(int X, int[] a, int n, int m) {
        int[] b = new int[n + 1];
        for (int i = 0; i < n; i++) {
            b[i + 1] = (a[i] >= X ? 2 : -1) + b[i];
        }
        int minB = Arrays.stream(b).min().getAsInt();
        for (int i = 0; i < b.length; i++) {
            b[i] -= minB;
        }
        BIT bit = new BIT(Collections.max(Arrays.asList(b)) + 2);
        long ans = 0;
        for (int x : b) {
            ans += bit.bitsum(x + 1);
            bit.bitadd(x, 1);
        }
        return ans >= m;
    }
}
