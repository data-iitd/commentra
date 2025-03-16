
import sys

# out is a helper function to print output.
def out(*args):
    print(*args)

# sc is a bufio.Scanner set up to read input in a word-by-word manner.
sc = bufio.Scanner(sys.stdin)

# getInt reads a single word from the input and converts it to an integer.
def getInt():
    sc.scan()
    return int(sc.text())

# getString reads a single word from the input and returns it as a string.
def getString():
    sc.scan()
    return sc.text()

# main function is the entry point of the program.
def main():
    # Set the split function for the scanner to split by words.
    sc.wordchars += '.'
    sc.whitespace =''

    # Set the buffer size for the scanner to a large value.
    sc.buffer = bytearray(1000000)

    # Read the number of elements (n) and the number of queries (q).
    n, q = getInt(), getInt()

    # Initialize a Fenwick Tree with n elements.
    fw = FenwickTree(n)

    # Read n elements and add them to the Fenwick Tree.
    for i in range(n):
        a = getInt()
        fw.add(i, a)

    # Process q queries.
    for i in range(q):
        t = getInt()
        if t == 0:
            # Update the value at position p by adding x to it.
            p, x = getInt(), getInt()
            fw.add(p, x)
        else:
            # Query the sum of elements between indices l and r.
            l, r = getInt(), getInt()
            out(fw.sum(l, r))

# Fenwick Tree implementation

# BIT represents the Fenwick Tree data structure.
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    # add updates the value at position p by adding x to it.
    def add(self, p, x):
        p += 1 # Convert to 1-based index
        while p <= self.n:
            self.data[p-1] += x
            p += p & -p # Move to the next node

    # sum calculates the sum of elements between indices l and r.
    def sum(self, l, r):
        return self.sum_to(r) - self.sum_to(l)

    # sum_to calculates the prefix sum up to index r.
    def sum_to(self, r):
        s = 0
        while r > 0:
            s += self.data[r-1]
            r -= r & -r # Move to the parent node
        return s

# Instantiate a Fenwick Tree with n elements.
fw = BIT(n)

# Read n elements and add them to the Fenwick Tree.
for i in range(n):
    a = getInt()
    fw.add(i, a)

# Process q queries.
for i in range(q):
    t = getInt()
    if t == 0:
        # Update the value at position p by adding x to it.
        p, x = getInt(), getInt()
        fw.add(p, x)
    else:
        # Query the sum of elements between indices l and r.
        l, r = getInt(), getInt()
        out(fw.sum(l, r))

