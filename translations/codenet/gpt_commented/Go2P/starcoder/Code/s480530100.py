# Python 3

# <START-OF-CODE>

# Fenwick Tree
#  1. Python have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    # Add updates the Fenwick Tree by adding x to the element at position p.
    def Add(self, p, x):
        p += 1 # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p-1] += x # Update the tree data
            p += p & -p # Move to the next index

    # Sum calculates the sum of elements in the range [l, r).
    def Sum(self, l, r):
        return self.sum(r) - self.sum(l) # Return the difference of sums

    # sum calculates the prefix sum from the start to index r.
    def sum(self, r):
        s = 0 # Initialize sum
        while r > 0:
            s += self.data[r-1] # Add the value at index r-1
            r -= r & -r # Move to the parent index
        return s # Return the calculated sum

# 