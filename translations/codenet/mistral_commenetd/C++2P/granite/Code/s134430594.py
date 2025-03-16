
import sys

# Define a class to store information about intervals
class Ban:
    def __init__(self, l, r, val):
        self.l = l
        self.r = r
        self.val = val

# Define a class to implement the segment tree
class Sp:
    LIM = 20
    N = 200007

    # An array to store the minimum value in each segment of the segment tree
    mn = [[0] * N for _ in range(LIM)]

    # A function to initialize the segment tree
    @staticmethod
    def init(a):
        n = len(a)
        # Initialize the first level of the segment tree
        for i in range(n):
            Sp.mn[0][i] = a[i]
        # Build the segment tree recursively
        for i in range(0, LIM - 1):
            for j in range(0, n - (1 << (i + 1)) + 1):
                Sp.mn[i + 1][j] = max(Sp.mn[i][j], Sp.mn[i][j + (1 << i)])

    # A function to get the minimum value in a segment of the segment tree
    @staticmethod
    def get(l, r):
        r += 1  # Adjust the index of the right endpoint of the segment to be one more than the actual index
        p = Sp.pw[r - l]  # Calculate the depth of the segment tree for the given segment
        return min(Sp.mn[p][l], Sp.mn[p][r - (1 << p)])  # Return the minimum value in the given segment

# Read the number of elements in the array
n = int(input())

# Read the elements of the array
a = list(map(int, input().split()))

# Initialize some variables
dl = [0] * n  # An array to store the difference between the index and the index of the element in the array
ans = 0  # The answer
bans = []  # A vector to store some information about the intervals

# Calculate the differences between the indices and the elements in the array
for i in range(n):
    if a[i] > i:  # Check if the element is out of its position
        print(-1)  # Output -1 if the element is out of its position
        sys.exit(0)
    dl[i] = i - a[i]  # Calculate the difference between the index and the element

# Calculate the answer and store some information about the intervals in a vector
for i in range(n):
    r = i  # Initialize a variable to store the right endpoint of the current interval
    while r + 1 < n and a[r] + 1 == a[r + 1]:  # Check if there is a longer interval with the same value
        r += 1  # Move to the next index if there is
    ans += a[r]  # Add the value of the right endpoint of the current interval to the answer
    i = r  # Update the index to be the right endpoint of the current interval
    bans.append(Ban(r - a[r], r, r - a[r]))  # Store some information about the current interval in the vector

# Initialize the segment tree using the differences between the indices and the elements in the array
Sp.init(dl)

# Check some conditions and calculate the answer if possible
for t in bans:
    if Sp.get(t.l, t.r) > t.val:  # Check if the minimum value in the segment of the segment tree is greater than the value of the interval
        print(-1)  # Output -1 if the condition is not satisfied
        sys.exit(0)

# Output the answer
print(ans)

