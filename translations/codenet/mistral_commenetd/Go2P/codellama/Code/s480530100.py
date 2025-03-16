
# A helper function to print output
def out(x):
    print(x)

# Initialize a scanner for reading input
sc = input

# Function to read an integer from the standard input
def getInt():
    return int(sc())

# Function to read a string from the standard input
def getString():
    return sc()

# Main function
def main():
    # Initialize the scanner for reading input
    # sc.Split(bufio.ScanWords)
    # sc.Buffer([]byte{}, 1000000)

    # Read the number of elements 'n' and the number of queries 'q' from the standard input
    n, q = getInt(), getInt()

    # Initialize a Fenwick Tree of size 'n'
    fw = FenwickTree(n)

    # Iterate through each element and add it to the Fenwick Tree
    for i in range(n):
        # Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
        a = getInt()
        fw.Add(i, a)

    # Iterate through each query
    for i in range(q):
        # Read an integer 't' from the standard input to determine the type of query
        t = getInt()

        # If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
        if t == 0:
            p, x = getInt(), getInt()
            fw.Add(p, x)
        else: # If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
            l, r = getInt(), getInt()
            # Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
            out(fw.Sum(l, r))

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    return sum(r) - sum(l)

def sum(r):
    s = 0
    while r > 0:
        s += data[r - 1]
        r -= r & -r
    return s

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
        self.data = [0] * (n + 1)

# FenwickTree :
def FenwickTree(n):
    return BIT(n)

# Add :
def Add(p, x):
    p += 1
    while p <= n:
        data[p - 1] += x
        p += p & -p

# Sum :
def Sum(l, r):
    