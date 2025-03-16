import java.util.*;

class BIT {
    private int size;  // Size of the binary indexed tree (BIT)
    private long[] tree;  // Tree array

    public BIT(int N) {
        this.size = N;  // Initialize the size
        this.tree = new long[N + 1];  // Initialize the tree array
    }

    private long bitsum(int i) {
        long ret = 0;  // Initialize the sum to 0
        while (i > 0) {
            ret += tree[i];  // Add the value at the current index
            i -= i & -i;  // Move to the parent index using the binary representation
        }
        return ret;  // Return the sum
    }

    public long bitsum(int l, Integer r) {
        if (r == null) {
            return bitsum(l);  // Calculate sum from 1 to l if r is not provided
        } else {
            return bitsum(r) - bitsum(l);  // Calculate sum from l to r
        }
    }

    public void bitadd(int i, long x) {
        i += 1;  // Convert to 1-based index
        while (i <= size) {
            tree[i] += x;  // Add x to the current index
            i += i & -i;  // Move to the next index
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements
        int n = scanner.nextInt();
        // Calculate the median position
        long m = n * (n + 1) / 4;
        // Read the list of elements and convert to indices
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Create a sorted set to handle unique values
        TreeSet<Integer> set = new TreeSet<>();
        for (int x : a) {
            set.add(x);
        }
        set.add(0);
        
        // Create a mapping from value to index
        Map<Integer, Integer> d = new HashMap<>();
        int index = 0;
        for (int x : set) {
            d.put(x, index++);
        }
        
        // Convert a to indices
        for (int i = 0; i < n; i++) {
            a[i] = d.get(a[i]);
        }

        // Function to check if the number of inversions is at least m
        boolean check(int X) {
            int[] b = new int[n + 1];
            b[0] = 0;
            for (int i = 0; i < n; i++) {
                b[i + 1] = b[i] + ((a[i] >= X) ? 1 : -1);  // Create a binary array
            }
            int minB = Arrays.stream(b).min().getAsInt();  // Normalize the array to be non-negative
            for (int i = 0; i <= n; i++) {
                b[i] -= minB;
            }
            BIT bit = new BIT(Arrays.stream(b).max().getAsInt() + 2);  // Initialize the BIT
            long ans = 0;
            for (int x : b) {
                ans += bit.bitsum(x + 1);  // Count inversions using the BIT
                bit.bitadd(x, 1);  // Add 1 to the current index in the BIT
            }
            return ans >= m;
        }

        // Binary search to find the value of X
        int[] t = {set.size(), 0};
        while (t[0] - t[1] > 1) {
            int mid = (t[0] + t[1]) / 2;
            if (check(mid)) {
                t[1] = mid;  // Update the lower bound
            } else {
                t[0] = mid;  // Update the upper bound
            }
        }

        // Output the median value
        System.out.println(new ArrayList<>(set).get(t[1]));
        scanner.close();
    }
}

// <END-OF-CODE>
