#######
# Class definition for BIT (Binary Indexed Tree)
# Initialize an instance of BIT with a given size N
#######
class BIT:
    def __init__(self, N):
        """
        Initialize an instance of BIT with a given size N.
        """
        self.size = N
        self.tree = [0] * (N + 1)  # Initialize tree array with zeros
        self.depth = N.bit_length()  # Calculate the depth of the tree

    # Helper function to calculate the sum of bits from index i to 0
    def _bitsum(self, i):
        """
        Calculate the sum of bits from index i to 0.
        """
        ret = 0
        while i:
            ret += self.tree[i]
            i &= i - 1  # Bitwise AND with the rightmost set bit
        return ret

    # Function to calculate the sum of bits from left index l to right index r
    def bitsum(self, l, r=None):
        """
        Calculate the sum of bits from left index l to right index r.
        If right index is not provided, calculate the sum of bits up to index l.
        """
        if r is None:
            return self._bitsum(l)
        else:
            return self._bitsum(r) - self._bitsum(l)

    # Function to add a value x to the index i in the tree
    def bitadd(self, i, x):
        """
        Add a value x to the index i in the tree.
        """
        i += 1  # Index i is 1-based in the tree
        while i <= self.size:
            self.tree[i] += x
            i += i & -i  # Bitwise right propagation

# Read input values
n = int(input())

# Calculate the size of the BIT tree
m = n * (n + 1) // 4

# Read input array a
a = list(map(int, input().split()))

# Create a dictionary d to map each unique value in a to its index
d = {}
_a = sorted(set(a + [0]))
for i, x in enumerate(_a):
    d[x] = i

# Replace the original array a with its indices in the dictionary d
a = [d[x] for x in a]

# Function to check if a given value X is a valid answer
def check(X):
    """
    Check if a given value X is a valid answer.
    """
    b = [0] + [(y >= X) * 2 - 1 for y in a]
    for i in range(n):
        b[i+1] += b[i]
    c = min(b)
    b = [x - c for x in b]
    bit = BIT(max(b) + 2)  # Initialize BIT tree with the maximum value in b + 2
    ans = 0
    for x in b:
        ans += bit.bitsum(x+1)  # Calculate the sum of bits from index x+1 to the end
        bit.bitadd(x, 1)  # Add 1 to the index x in the tree
    return ans >= m

# Binary search to find the answer
t = [len(_a), 0]
while t[0] - t[1] > 1:
    mid = (t[0] + t[1]) // 2
    t[check(mid)] = mid

# Print the answer
print(_a[t[1]])
