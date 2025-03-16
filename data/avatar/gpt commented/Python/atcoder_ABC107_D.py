class BIT:
    # Initialize the Binary Indexed Tree (BIT) with size N
    def __init__(self, N):
        self.size = N  # Store the size of the BIT
        self.tree = [0] * (N + 1)  # Initialize the BIT array with zeros
        self.depth = N.bit_length()  # Calculate the depth of the BIT

    # Internal method to calculate the prefix sum up to index i
    def _bitsum(self, i):
        ret = 0  # Initialize the sum
        while i:
            ret += self.tree[i]  # Add the value at index i to the sum
            i ^= i & -i  # Move to the parent index
        return ret  # Return the calculated sum

    # Public method to calculate the sum in the range [l, r]
    def bitsum(self, l, r=None):
        if r is None:
            return self._bitsum(l)  # If r is not provided, return the sum up to l
        else:
            return self._bitsum(r) - self._bitsum(l)  # Return the sum in the range [l, r]

    # Method to add a value x at index i
    def bitadd(self, i, x):
        i += 1  # Adjust index to match BIT's 1-based indexing
        while i <= self.size:
            self.tree[i] += x  # Update the BIT with the value x
            i += i & -i  # Move to the next index
        return

# Read the number of elements
n = int(input())
# Calculate the target value m based on the number of elements
m = n * (n + 1) // 4
# Read the input array and convert it to a list of integers
a = list(map(int, input().split()))
d = dict()  # Dictionary to hold the mapping of values to their indices
# Create a sorted list of unique values from a, including 0
_a = sorted(set(a + [0]))

# Map original values to their indices in the sorted list
for i, x in enumerate(_a):
    d[x] = i
# Replace original values in a with their corresponding indices
a = [d[x] for x in a]

# Function to check if a certain value X can be achieved
def check(X):
    # Create a new list b where each element indicates if the corresponding a[i] is >= X
    b = [0] + [(y >= X) * 2 - 1 for y in a]
    # Calculate the prefix sums of b
    for i in range(n):
        b[i + 1] += b[i]
    c = min(b)  # Find the minimum value in b
    b = [x - c for x in b]  # Normalize b by subtracting the minimum value
    bit = BIT(max(b) + 2)  # Initialize a BIT for the range of b
    ans = 0  # Initialize the answer counter
    # Count the number of valid pairs using the BIT
    for x in b:
        ans += bit.bitsum(x + 1)  # Count how many indices have been added that are less than x
        bit.bitadd(x, 1)  # Add the current index to the BIT
    return ans >= m  # Return whether the count is at least m

# Initialize the binary search bounds
t = [len(_a), 0]
# Perform binary search to find the maximum value that satisfies the condition
while t[0] - t[1] > 1:
    mid = (t[0] + t[1]) // 2  # Calculate the midpoint
    t[check(mid)] = mid  # Update the bounds based on the check function

# Print the result corresponding to the found index
print(_a[t[1]])
