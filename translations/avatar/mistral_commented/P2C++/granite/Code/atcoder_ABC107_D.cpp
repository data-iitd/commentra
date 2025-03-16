
#####
# Class definition for BIT (Binary Indexed Tree)
# Initialize an instance of BIT with a given size N
#####
class BIT {
public:
    BIT(int N) : size(N), tree(N + 1, 0), depth(N.bit_length()) {}

    // Helper function to calculate the sum of bits from index i to 0
    int _bitsum(int i) {
        int ret = 0;
        while (i) {
            ret += tree[i];
            i &= i - 1;  // Bitwise AND with the rightmost set bit
        }
        return ret;
    }

    // Function to calculate the sum of bits from left index l to right index r
    int bitsum(int l, int r = -1) {
        if (r == -1) return _bitsum(l);
        else return _bitsum(r) - _bitsum(l);
    }

    // Function to add a value x to the index i in the tree
    void bitadd(int i, int x) {
        i++;  // Index i is 1-based in the tree
        while (i <= size) {
            tree[i] += x;
            i += i & -i;  // Bitwise right propagation
        }
    }

private:
    int size;
    vector<int> tree;
    int depth;
};

// Read input values
int n;
cin >> n;

// Calculate the size of the BIT tree
int m = n * (n + 1) / 4;

// Read input array a
vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];

// Create a dictionary d to map each unique value in a to its index
map<int, int> d;
vector<_a> _a(a.begin(), a.end());
_a.push_back(0);
sort(_a.begin(), _a.end());
_a.erase(unique(_a.begin(), _a.end()), _a.end());
for (int i = 0; i < _a.size(); i++) d[_a[i]] = i;

// Replace the original array a with its indices in the dictionary d
for (int i = 0; i < n; i++) a[i] = d[a[i]];

// Function to check if a given value X is a valid answer
bool check(int X) {
    vector<int> b(n + 1);
    for (int i = 0; i < n; i++) b[i + 1] = (a[i] >= X) * 2 - 1;
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];
    int c = *min_element(b.begin(), b.end());
    for (int i = 0; i <= n; i++) b[i] -= c;
    BIT bit(max(b) + 2);  // Initialize BIT tree with the maximum value in b + 2
    int ans = 0;
    for (int x : b) {
        ans += bit.bitsum(x + 1);  // Calculate the sum of bits from index x+1 to the end
        bit.bitadd(x, 1);  // Add 1 to the index x in the tree
    }
    return ans >= m;
}

// Binary search to find the answer
int t[2] = {d.size(), 0};
while (t[0] - t[1] > 1) {
    int mid = (t[0] + t[1]) / 2;
    if (check(mid)) t[1] = mid;
    else t[0] = mid;
}

// Print the answer
cout << _a[t[1]] << endl;

