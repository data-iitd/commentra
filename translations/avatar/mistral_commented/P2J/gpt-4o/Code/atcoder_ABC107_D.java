import java.util.*;

class BIT {
    private int size;
    private int[] tree;

    public BIT(int N) {
        this.size = N;
        this.tree = new int[N + 1]; // Initialize tree array with zeros
    }

    // Helper function to calculate the sum of bits from index i to 0
    private int bitsum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i &= (i - 1); // Bitwise AND with the rightmost set bit
        }
        return ret;
    }

    // Function to calculate the sum of bits from left index l to right index r
    public int bitsum(int l, Integer r) {
        if (r == null) {
            return bitsum(l);
        } else {
            return bitsum(r) - bitsum(l);
        }
    }

    // Function to add a value x to the index i in the tree
    public void bitadd(int i, int x) {
        i += 1; // Index i is 1-based in the tree
        while (i <= size) {
            tree[i] += x;
            i += (i & -i); // Bitwise right propagation
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values
        int n = scanner.nextInt();

        // Calculate the size of the BIT tree
        int m = n * (n + 1) / 4;

        // Read input array a
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Create a dictionary d to map each unique value in a to its index
        Map<Integer, Integer> d = new HashMap<>();
        TreeSet<Integer> uniqueValues = new TreeSet<>(Arrays.asList(a));
        uniqueValues.add(0);
        int index = 0;
        for (int x : uniqueValues) {
            d.put(x, index++);
        }

        // Replace the original array a with its indices in the dictionary d
        for (int i = 0; i < n; i++) {
            a[i] = d.get(a[i]);
        }

        // Function to check if a given value X is a valid answer
        boolean check(int X) {
            int[] b = new int[n + 1];
            b[0] = 0;
            for (int i = 0; i < n; i++) {
                b[i + 1] = b[i] + ((a[i] >= X) ? 1 : -1);
            }
            int c = Arrays.stream(b).min().getAsInt();
            for (int i = 0; i <= n; i++) {
                b[i] -= c;
            }
            BIT bit = new BIT(Arrays.stream(b).max().getAsInt() + 2); // Initialize BIT tree
            int ans = 0;
            for (int x : b) {
                ans += bit.bitsum(x + 1, null); // Calculate the sum of bits from index x+1 to the end
                bit.bitadd(x, 1); // Add 1 to the index x in the tree
            }
            return ans >= m;
        }

        // Binary search to find the answer
        int[] t = {uniqueValues.size(), 0};
        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            if (check(mid)) {
                t[1] = mid;
            } else {
                t[0] = mid;
            }
        }

        // Print the answer
        System.out.println(uniqueValues.toArray()[t[1]]);
        scanner.close();
    }
}

// <END-OF-CODE>
