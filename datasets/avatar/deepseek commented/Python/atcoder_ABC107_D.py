class BIT :
    def __init__ ( self , N ) :
        self.size = N  # Initialize the size of the binary indexed tree (BIT)
        self.tree = [ 0 ] * ( N + 1 )  # Initialize the tree array
        self.depth = N.bit_length()  # Calculate the depth of the BIT

    def _bitsum(self, i):
        ret = 0  # Initialize the sum to 0
        while i:
            ret += self.tree[i]  # Add the value at the current index
            i ^= i & -i  # Move to the parent index using the binary representation
        return ret  # Return the sum

    def bitsum(self, l, r=None):
        if r is None:
            return self._bitsum(l)  # Calculate sum from 1 to l if r is not provided
        else:
            return self._bitsum(r) - self._bitsum(l)  # Calculate sum from l to r

    def bitadd(self, i, x):
        i += 1  # Convert to 1-based index
        while i <= self.size:
            self.tree[i] += x  # Add x to the current index
            i += i & -i  # Move to the next index
        return

# Read the number of elements
n = int(input())
# Calculate the median position
m = n * (n + 1) // 4
# Read the list of elements and convert to indices
a = list(map(int, input().split()))
d = dict()
_a = sorted(set(a + [0]))
for i, x in enumerate(_a):
    d[x] = i
a = [d[x] for x in a]

# Function to check if the number of inversions is at least m
def check(X):
    b = [0] + [(y >= X) * 2 - 1 for y in a]  # Create a binary array
    for i in range(n):
        b[i + 1] += b[i]  # Prefix sum to get the cumulative sum
    c = min(b)  # Normalize the array to be non-negative
    b = [x - c for x in b]
    bit = BIT(max(b) + 2)  # Initialize the BIT
    ans = 0
    for x in b:
        ans += bit.bitsum(x + 1)  # Count inversions using the BIT
        bit.bitadd(x, 1)  # Add 1 to the current index in the BIT
    return ans >= m

# Binary search to find the value of X
t = [len(_a), 0]
while t[0] - t[1] > 1:
    mid = (t[0] + t[1]) // 2
    t[check(mid)] = mid

# Output the median value
print(_a[t[1]])
