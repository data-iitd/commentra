
# Define a struct to store information about intervals
class Ban:
    def __init__(self, l_, r_, val_):
        self.l = l_
        self.r = r_
        self.val = val_

# Define a class to store the segment tree
class Sp:
    LIM = 20 # Maximum depth of the segment tree
    N = 2e5 + 7 # Maximum number of elements in the array

    # An array to store the minimum value in each segment of the segment tree
    mn = [[0] * N for _ in range(LIM)]

    # A function to initialize the segment tree
    def init(self, a):
        n = len(a)
        # Initialize the first level of the segment tree
        for i in range(n):
            self.mn[0][i] = a[i] # Store the value of the element at index i in the first level of the segment tree
        # Build the segment tree recursively
        for i in range(0, LIM - 1):
            for j in range(0, n - (1 << i)):
                self.mn[i + 1][j] = max(self.mn[i][j], self.mn[i][j + (1 << i)]) # Find the minimum value in the current segment and store it in the next level of the segment tree
        # Calculate the power of 2 up to the maximum depth of the segment tree
        self.pw = [0] * N
        self.pw[1] = 0
        for i in range(2, N):
            self.pw[i] = self.pw[i // 2] + 1 # Calculate the power of 2 for each index

    # A function to get the minimum value in a segment of the segment tree
    def get(self, l, r):
        r += 1 # Adjust the index of the right endpoint of the segment to be one more than the actual index
        p = self.pw[r - l] # Calculate the depth of the segment tree for the given segment
        return min(self.mn[p][l], self.mn[p][r - (1 << p)]) # Return the minimum value in the given segment

# Read the number of elements in the array
n = int(input())

# Read the elements of the array
a = [int(input()) for _ in range(n)]

# Initialize some variables
dl = [0] * n # An array to store the difference between the index and the index of the element in the array
ans = 0 # The answer
bans = [] # A vector to store some information about the intervals

# Calculate the differences between the indices and the elements in the array
for i in range(n):
    if a[i] > i: # Check if the element is out of its position
        print(-1) # Output -1 if the element is out of its position
        exit()
    dl[i] = i - a[i] # Calculate the difference between the index and the element

# Calculate the answer and store some information about the intervals in a vector
for i in range(n):
    r = i # Initialize a variable to store the right endpoint of the current interval
    while r + 1 < n and a[r] + 1 == a[r + 1]: # Check if there is a longer interval with the same value
        r += 1 # Move to the next index if there is
    ans += a[r] # Add the value of the right endpoint of the current interval to the answer
    i = r # Update the index to be the right endpoint of the current interval
    bans.append(Ban(r - a[r], r, r - a[r])) # Store some information about the current interval in the vector

# Initialize the segment tree using the differences between the indices and the elements in the array
sp = Sp()
sp.init(dl)

# Check some conditions and calculate the answer if possible
for t in bans:
    if sp.get(t.l, t.r) > t.val: # Check if the minimum value in the segment of the segment tree is greater than the value of the interval
        print(-1) # Output -1 if the condition is not satisfied
        exit()

# Output the answer
print(ans)

