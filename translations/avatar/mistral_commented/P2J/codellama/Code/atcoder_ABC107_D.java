#######
# Class definition for BIT (Binary Indexed Tree)
# Initialize an instance of BIT with a given size N
#######
class BIT {
    private int size;
    private int[] tree;
    private int depth;

    public BIT(int N) {
        size = N;
        tree = new int[N + 1];
        depth = (int) Math.floor(Math.log(N) / Math.log(2)) + 1;
    }

    // Helper function to calculate the sum of bits from index i to 0
    private int bitsum(int i) {
        int ret = 0;
        while (i > 0) {
            ret += tree[i];
            i &= i - 1;
        }
        return ret;
    }

    // Function to calculate the sum of bits from left index l to right index r
    public int bitsum(int l, int r) {
        if (r == -1) {
            return bitsum(l);
        } else {
            return bitsum(r) - bitsum(l);
        }
    }

    // Function to add a value x to the index i in the tree
    public void bitadd(int i, int x) {
        i++;
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }
}

// Read input values
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Calculate the size of the BIT tree
int m = n * (n + 1) / 4;

// Read input array a
int[] a = new int[n];
for (int i = 0; i < n; i++) {
    a[i] = sc.nextInt();
}

// Create a dictionary d to map each unique value in a to its index
HashMap<Integer, Integer> d = new HashMap<>();
int[] _a = a.clone();
Arrays.sort(_a);
for (int i = 0; i < _a.length; i++) {
    d.put(_a[i], i);
}

// Replace the original array a with its indices in the dictionary d
for (int i = 0; i < n; i++) {
    a[i] = d.get(a[i]);
}

// Function to check if a given value X is a valid answer
boolean check(int X) {
    int[] b = new int[n + 1];
    for (int i = 0; i < n; i++) {
        b[i + 1] = (a[i] >= X) ? 2 : -1;
    }
    for (int i = 0; i < n; i++) {
        b[i + 1] += b[i];
    }
    int c = Arrays.stream(b).min().getAsInt();
    for (int i = 0; i < n; i++) {
        b[i] -= c;
    }
    BIT bit = new BIT(b[n]);
    int ans = 0;
    for (int x : b) {
        ans += bit.bitsum(x + 1);
        bit.bitadd(x, 1);
    }
    return ans >= m;
}

// Binary search to find the answer
int[] t = {_a.length, 0};
while (t[0] - t[1] > 1) {
    int mid = (t[0] + t[1]) / 2;
    t[check(_a[mid]) ? 0 : 1] = mid;
}

// Print the answer
System.out.println(_a[t[1]]);

