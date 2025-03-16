import sys
import io

# A helper function to print output
def out(x):
    print(x)

# Function to read an integer from the standard input
def get_int():
    return int(sys.stdin.readline().strip())

# Function to read a string from the standard input
def get_string():
    return sys.stdin.readline().strip()

# Main function
def main():
    # Read the number of elements 'n' and the number of queries 'q' from the standard input
    n, q = map(int, sys.stdin.readline().strip().split())

    # Initialize a Fenwick Tree of size 'n'
    fw = FenwickTree(n)

    # Iterate through each element and add it to the Fenwick Tree
    for i in range(n):
        # Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
        a = get_int()
        fw.add(i, a)

    # Iterate through each query
    for i in range(q):
        # Read an integer 't' from the standard input to determine the type of query
        t = get_int()

        # If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
        if t == 0:
            p, x = map(int, sys.stdin.readline().strip().split())
            fw.add(p, x)
        else: # If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
            l, r = map(int, sys.stdin.readline().strip().split())
            # Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
            out(fw.sum(l, r))

# ** copy from here to your source code **
#
# fenwick tree
#  1. go lang have no generics, so implement int(long long)
#  data type only.
#  2. do not care overflow
#

# BIT :
class BIT:
    def __init__(self, n):
        self.n = n
        self.data = [0] * n

    # Add :
    def add(self, p, x):
        p += 1
        while p <= self.n:
            self.data[p - 1] += x
            p += p & -p

    # Sum :
    def sum(self, l, r):
        return self._sum(r) - self._sum(l)

    def _sum(self, r):
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r
        return s

# Initialize the scanner for reading input
# sc = bufio.NewScanner(os.Stdin)
# sc.Split(bufio.ScanWords)
# sc.Buffer([]byte{}, 1000000)

# Main function call
if __name__ == "__main__":
    main()
