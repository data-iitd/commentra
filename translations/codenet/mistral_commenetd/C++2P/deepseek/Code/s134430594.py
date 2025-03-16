import sys
import math

# Define a class to store information about intervals
class Ban:
    def __init__(self, l, r, val):
        self.l = l
        self.r = r
        self.val = val

# Define a namespace to store some constants and functions
class Sp:
    LIM = 20  # Maximum depth of the segment tree
    N = 200007  # Maximum number of elements in the array
    mn = [[0] * N for _ in range(LIM)]  # An array to store the minimum value in each segment of the segment tree
    pw = [0] * N  # An array to store the power of 2 for each index

    # A function to initialize the segment tree
    @staticmethod
    def init(a):
        n = len(a)
        # Initialize the first level of the segment tree
        for i in range(n):
            Sp.mn[0][i] = a[i]  # Store the value of the element at index i in the first level of the segment tree
        # Build the segment tree recursively
        for i in range(Sp.LIM - 1):
            for j in range(n - (1 << (i + 1)) + 1):
                Sp.mn[i + 1][j] = max(Sp.mn[i][j], Sp.mn[i][j + (1 << i)])  # Find the minimum value in the current segment and store it in the next level of the segment tree
        # Calculate the power of 2 up to the maximum depth of the segment tree
        Sp.pw[1] = 0
        for i in range(2, Sp.N):
            Sp.pw[i] = Sp.pw[i // 2] + 1  # Calculate the power of 2 for each index

    # A function to get the minimum value in a segment of the segment tree
    @staticmethod
    def get(l, r):
        r += 1  # Adjust the index of the right endpoint of the segment to be one more than the actual index
        p = Sp.pw[r - l]  # Calculate the depth of the segment tree for the given segment
        return min(Sp.mn[p][l], Sp.mn[p][r - (1 << p)])  # Return the minimum value in the given segment

# Read the number of elements in the array
n = int(sys.stdin.readline().strip())

# Read the elements of the array
a = list(map(int, sys.stdin.readline().strip().split()))

# Initialize some variables
dl = [0] * n  # An array to store the difference between the index and the index of the element in the array
ans = 0  # The answer
bans = []  # A list to store some information about the intervals

# Calculate the differences between the indices and the elements in the array
for i in range(n):
    if a[i] > i:  # Check if the element is out of its position
        print(-1)  # Output -1 if the element is out of its position
        sys.exit(0)
    dl[i] = i - a[i]  # Calculate the difference between the index and the element

# Calculate the answer and store some information about the intervals in a list
for i in range(n):
    r = i
    # Check if there is a longer interval with the same value
    while r + 1 < n and a[r] + 1 == a[r + 1]:
        r += 1  # Move to the next index if there is
    ans += a[r]  # Add the value of the right endpoint of the current interval to the answer
    i = r  # Update the index to be the right endpoint of the current interval
    bans.append(Ban(r - a[r], r, r - a[r]))  # Store some information about the current interval in the list

# Initialize the segment tree using the differences between the indices and the elements in the array
Sp.init(dl)

# Check some conditions and calculate the answer if possible
for t in bans:
    if Sp.get(t.l, t.r) > t.val:  # Check if the minimum value in the segment of the segment tree is greater than the value of the interval
        print(-1)  # Output -1 if the condition is not satisfied
        sys.exit(0)

# Output the answer
print(ans)
