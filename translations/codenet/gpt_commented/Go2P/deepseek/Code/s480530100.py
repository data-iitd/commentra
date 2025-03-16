import sys
import io

# out is a utility function to print output to the console.
def out(x):
    print(x)

# Initialize a new scanner to read input from standard input.
class Scanner:
    def __init__(self, input):
        self.tokens = []
        self.token_index = 0
        self.input = input

    def next_token(self):
        while self.token_index >= len(self.tokens):
            line = self.input.readline()
            if not line:
                return None
            self.tokens = line.split()
            self.token_index = 0
        token = self.tokens[self.token_index]
        self.token_index += 1
        return token

    def next_int(self):
        token = self.next_token()
        if token is None:
            raise ValueError("No more tokens available")
        return int(token)

    def next_string(self):
        token = self.next_token()
        if token is None:
            raise ValueError("No more tokens available")
        return token

# Set up the scanner to read from standard input.
input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
sc = Scanner(input_stream)

# Read the number of elements (n) and the number of queries (q).
n = sc.next_int()
q = sc.next_int()

# Initialize a new Fenwick Tree (Binary Indexed Tree) with n elements.
fw = FenwickTree(n)

# Read n integers and add them to the Fenwick Tree.
for i in range(n):
    a = sc.next_int()
    fw.add(i, a)

# Process q queries.
for i in range(q):
    t = sc.next_int()  # Read the type of query.
    if t == 0:
        # For update queries, read position (p) and value (x) and update the Fenwick Tree.
        p = sc.next_int()
        x = sc.next_int()
        fw.add(p, x)
    else:
        # For sum queries, read the range (l, r) and output the sum from l to r.
        l = sc.next_int()
        r = sc.next_int()
        out(fw.sum(l, r))

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT represents a Binary Indexed Tree (Fenwick Tree).
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    # Add updates the Fenwick Tree by adding x to the element at position p.
    def add(self, p, x):
        p += 1  # Increment p to match the 1-based index used in Fenwick Tree
        while p <= self.n:
            self.data[p - 1] += x  # Update the tree data
            p += p & -p  # Move to the next index

    # Sum calculates the sum of elements in the range [l, r).
    def sum(self, l, r):
        return self._sum(r) - self._sum(l)  # Return the difference of sums

    # sum calculates the prefix sum from the start to index r.
    def _sum(self, r):
        s = 0  # Initialize sum
        while r > 0:
            s += self.data[r - 1]  # Add the value at index r-1
            r -= r & -r  # Move to the parent index
        return s  # Return the calculated sum

# FenwickTree initializes a new Binary Indexed Tree with n elements.
def FenwickTree(n):
    return BIT(n)

