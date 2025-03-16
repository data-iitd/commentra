import sys
import math

# Define a class to represent a range with a value
class Ban:
    def __init__(self, l, r, val):
        self.l = l  # Left index of the range
        self.r = r  # Right index of the range
        self.val = val  # Value associated with the range

class SparseTable:
    LIM = 20
    N = 200007

    def __init__(self):
        self.mn = [[0] * self.N for _ in range(self.LIM)]
        self.pw = [0] * self.N
        self.init_powers()

    def init_powers(self):
        for i in range(2, self.N):
            self.pw[i] = self.pw[i // 2] + 1

    def init(self, a):
        n = len(a)
        for i in range(n):
            self.mn[0][i] = a[i]
        for i in range(self.LIM - 1):
            for j in range(n - (1 << (i + 1)) + 1):
                self.mn[i + 1][j] = max(self.mn[i][j], self.mn[i][j + (1 << i)])

    def get(self, l, r):
        r += 1
        p = self.pw[r - l]
        return min(self.mn[p][l], self.mn[p][r - (1 << p)])

def main():
    # Optimize input/output
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements
    a = list(map(int, data[1:n + 1]))  # Read the elements into the list

    # Vector to store the difference between index and value
    dl = [0] * n
    for i in range(n):
        if a[i] > i:
            print(-1)  # Output -1 if the condition fails
            return
        dl[i] = i - a[i]

    # Initialize answer and list to store ranges
    ans = 0
    bans = []
    i = 0
    while i < n:
        r = i
        # Extend the range while the next value is consecutive
        while r + 1 < n and a[r] + 1 == a[r + 1]:
            r += 1
        # Update the answer with the maximum value in the range
        ans += a[r]
        # Store the range in the bans list
        bans.append(Ban(r - a[r], r, r - a[r]))
        i = r  # Move to the end of the current range

    # Initialize the sparse table with the difference list
    sp = SparseTable()
    sp.init(dl)
    # Check each range for validity
    for t in bans:
        # If the minimum value in the range exceeds the stored value, output -1
        if sp.get(t.l, t.r) > t.val:
            print(-1)
            return
    # Output the final answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
