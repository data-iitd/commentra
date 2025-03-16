import java.util.*;

public class BIT {
    private int size;
    private int[] tree;

    public BIT(int N) {
        this.size = N;
        this.tree = new int[N + 1];
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
        i++;
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
        List<Integer> _a = new ArrayList<>(new HashSet<>(Arrays.asList(a)));
        _a.add(0);
        Collections.sort(_a);
        for (int i = 0; i < _a.size(); i++) {
            d.put(_a.get(i), i);
        }
        for (int i = 0; i < n; i++) {
            a[i] = d.get(a[i]);
        }

        // Function to check if the number of inversions is at least m
        boolean check(int X) {
            int[] b = new int[n + 1];
            for (int i = 0; i < n; i++) {
                b[i + 1] = ((a[i] >= X) ? 2 : -1) + b[i];
            }
            int c = Collections.min(Arrays.stream(b).boxed().collect(Collectors.toList()));
            for (int i = 0; i < b.length; i++) {
                b[i] -= c;
            }
            BIT bit = new BIT(Collections.max(Arrays.stream(b).boxed().collect(Collectors.toList())) + 2);
            int ans = 0;
            for (int x : b) {
                ans += bit.bitsum(x + 1, x + 1);
                bit.bitadd(x, 1);
            }
            return ans >= m;
        }

        // Binary search to find the value of X
        int[] t = {_a.size(), 0};
        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            t[check(mid) ? 0 : 1] = mid;
        }

        // Output the median value
        System.out.println(_a.get(t[1]));
    }
}
