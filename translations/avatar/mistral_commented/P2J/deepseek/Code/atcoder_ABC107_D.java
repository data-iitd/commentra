import java.util.*;

class BIT {
    private int size;
    private int[] tree;

    public BIT(int N) {
        this.size = N;
        this.tree = new int[N + 1];
    }

    // Helper function to calculate the sum of bits from index i to 0
    private int _bitsum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i &= i - 1; // Bitwise AND with the rightmost set bit
        }
        return ret;
    }

    // Function to calculate the sum of bits from left index l to right index r
    public int bitsum(int l, int r) {
        return _bitsum(r) - _bitsum(l - 1);
    }

    // Function to add a value x to the index i in the tree
    public void bitadd(int i, int x) {
        i += 1; // Index i is 1-based in the tree
        while (i <= size) {
            tree[i] += x;
            i += i & -i; // Bitwise right propagation
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
        Integer[] _a = Arrays.stream(a).boxed().distinct().toArray(Integer[]::new);
        Arrays.sort(_a);
        for (int i = 0; i < _a.length; i++) {
            d.put(_a[i], i);
        }
        a = Arrays.stream(a).mapToInt(x -> d.get(x)).toArray();

        // Function to check if a given value X is a valid answer
        boolean check(int X) {
            int[] b = new int[n + 1];
            for (int i = 0; i < n; i++) {
                b[i + 1] = ((a[i] >= X) ? 2 : -1) + b[i];
            }
            int c = Arrays.stream(b).min().getAsInt();
            for (int i = 0; i <= n; i++) {
                b[i] -= c;
            }
            BIT bit = new BIT(Arrays.stream(b).max().getAsInt() + 2);
            int ans = 0;
            for (int x : b) {
                ans += bit.bitsum(x + 1, bit.size);
                bit.bitadd(x, 1);
            }
            return ans >= m;
        }

        // Binary search to find the answer
        int[] t = {_a.length, 0};
        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            t[check(mid) ? 0 : 1] = mid;
        }

        // Print the answer
        System.out.println(_a[t[1]]);
    }
}
