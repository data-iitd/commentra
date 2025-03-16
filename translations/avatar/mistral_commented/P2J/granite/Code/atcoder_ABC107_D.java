
#####
# Class definition for BIT (Binary Indexed Tree)
# Initialize an instance of BIT with a given size N
#####
class BIT {
    private int[] tree;
    private int size;
    private int depth;

    // Constructor to initialize an instance of BIT with a given size N
    public BIT(int N) {
        size = N;
        tree = new int[N + 1];  // Initialize tree array with zeros
        depth = N.bitLength();  // Calculate the depth of the tree
    }

    // Helper function to calculate the sum of bits from index i to 0
    private int _bitsum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i &= i - 1;  // Bitwise AND with the rightmost set bit
        }
        return ret;
    }

    // Function to calculate the sum of bits from left index l to right index r
    public int bitsum(int l, int r) {
        if (r == null) {
            return _bitsum(l);
        } else {
            return _bitsum(r) - _bitsum(l);
        }
    }

    // Function to add a value x to the index i in the tree
    public void bitadd(int i, int x) {
        i++;  // Index i is 1-based in the tree
        while (i <= size) {
            tree[i] += x;
            i += i & -i;  // Bitwise right propagation
        }
    }
}

// Read input values
Scanner scanner = new Scanner(System.in);
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
List<Integer> _a = new ArrayList<>(Arrays.asList(a));
_a.add(0);
Collections.sort(_a);
for (int i = 0; i < _a.size(); i++) {
    d.put(_a.get(i), i);
}

// Replace the original array a with its indices in the dictionary d
for (int i = 0; i < n; i++) {
    a[i] = d.get(a[i]);
}

// Function to check if a given value X is a valid answer
boolean check(int X) {
    int[] b = new int[n + 1];
    for (int i = 0; i < n; i++) {
        b[i + 1] = (a[i] >= X)? 2 : -1;
    }
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }
    int c = Arrays.stream(b).min().getAsInt();
    for (int i = 0; i <= n; i++) {
        b[i] -= c;
    }
    BIT bit = new BIT(Arrays.stream(b).max().getAsInt() + 2);
    int ans = 0;
    for (int x : b) {
        ans += bit.bitsum(x + 1);  // Calculate the sum of bits from index x+1 to the end
        bit.bitadd(x, 1);  // Add 1 to the index x in the tree
    }
    return ans >= m;
}

// Binary search to find the answer
int[] t = {Collections.frequency(_a, _a.get(_a.size() - 1)), 0};
while (t[0] - t[1] > 1) {
    int mid = (t[0] + t[1]) / 2;
    t[check(mid)] = mid;
}

// Print the answer
System.out.println(_a.get(t[1]));
