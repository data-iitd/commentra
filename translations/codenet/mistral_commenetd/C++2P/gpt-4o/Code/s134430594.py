import sys
import math
from collections import deque

# Define a class to store information about intervals
class Ban:
    def __init__(self, l, r, val):
        self.l = l  # left endpoint of the interval
        self.r = r  # right endpoint of the interval
        self.val = val  # value of the interval

class SegmentTree:
    LIM = 20  # Maximum depth of the segment tree
    N = 200007  # Maximum number of elements in the array

    def __init__(self, a):
        self.mn = [[0] * self.N for _ in range(self.LIM)]
        self.pw = [0] * self.N
        self.init(a)

    def init(self, a):
        n = len(a)
        # Initialize the first level of the segment tree
        for i in range(n):
            self.mn[0][i] = a[i]  # Store the value of the element at index i in the first level of the segment tree
        # Build the segment tree recursively
        for i in range(self.LIM - 1):
            for j in range(n - (1 << (i + 1)) + 1):
                self.mn[i + 1][j] = max(self.mn[i][j], self.mn[i][j + (1 << i)])  # Find the maximum value in the current segment

        # Calculate the power of 2 up to the maximum depth of the segment tree
        for i in range(2, self.N):
            self.pw[i] = self.pw[i // 2] + 1  # Calculate the power of 2 for each index

    def get(self, l, r):
        r += 1  # Adjust the index of the right endpoint of the segment to be one more than the actual index
        p = self.pw[r - l]  # Calculate the depth of the segment tree for the given segment
        return min(self.mn[p][l], self.mn[p][r - (1 << p)])  # Return the minimum value in the given segment

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])  # Read the number of elements in the array
    a = list(map(int, data[1:n + 1]))  # Read the elements of the array

    dl = [0] * n  # An array to store the difference between the index and the index of the element in the array
    ans = 0  # The answer
    bans = []  # A list to store some information about the intervals

    # Calculate the differences between the indices and the elements in the array
    for i in range(n):
        if a[i] > i:  # Check if the element is out of its position
            print(-1)  # Output -1 if the element is out of its position
            return
        dl[i] = i - a[i]  # Calculate the difference between the index and the element

    # Calculate the answer and store some information about the intervals in a list
    i = 0
    while i < n:
        r = i  # Initialize a variable to store the right endpoint of the current interval
        while r + 1 < n and a[r] + 1 == a[r + 1]:  # Check if there is a longer interval with the same value
            r += 1  # Move to the next index if there is
        ans += a[r]  # Add the value of the right endpoint of the current interval to the answer
        i = r  # Update the index to be the right endpoint of the current interval
        bans.append(Ban(r - a[r], r, r - a[r]))  # Store some information about the current interval in the list
        i += 1

    # Initialize the segment tree using the differences between the indices and the elements in the array
    seg_tree = SegmentTree(dl)

    # Check some conditions and calculate the answer if possible
    for t in bans:
        if seg_tree.get(t.l, t.r) > t.val:  # Check if the minimum value in the segment of the segment tree is greater than the value of the interval
            print(-1)  # Output -1 if the condition is not satisfied
            return

    # Output the answer
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
