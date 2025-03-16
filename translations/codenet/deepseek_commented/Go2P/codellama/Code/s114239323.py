
# Reads the next integer from the input
def nextInt():
    return nextInt() # Comment: Reads the next integer from the input

# Reads a slice of integers of length N
def nextInts(N):
    return nextInts(N) # Comment: Reads a slice of integers of length N

# Main function to solve the problem
def main():
    # Reads the number of steps N
    N = nextInt() # Comment: Reads the number of steps N
    
    # Reads the list of heights h
    h = nextInts(N) # Comment: Reads the list of heights h
    
    # Initializes the DP array with zeros
    dp = [0] * N # Comment: Initializes the DP array with zeros
    
    # Sets the cost to reach the second step
    dp[1] = abs(h[0] - h[1]) # Comment: Sets the cost to reach the second step
    
    # Computes the minimum cost to reach each step using dynamic programming
    for i in range(2, N):
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                    dp[i - 2] + abs(h[i] - h[i - 2]))
    
    # Prints the minimum cost to reach the last step
    print(dp[N-1]) # Comment: Prints the minimum cost to reach the last step

# Utility function to find the absolute value of an integer
def abs(a):
    if a < 0:
        return -a
    return a

# Utility function to find the maximum value in a slice of integers
def max(a):
    r = a[0]
    for i in range(len(a)):
        if r < a[i]:
            r = a[i]
    return r

# Utility function to find the minimum value in a slice of integers
def min(a):
    r = a[0]
    for i in range(len(a)):
        if r > a[i]:
            r = a[i]
    return r

# Utility function to calculate the sum of a slice of integers
def sum(a):
    r = 0
    for i in range(len(a)):
        r += a[i]
    return r

# Pair struct to represent a pair of integers
class Pair:
    def __init__(self, a, b):
        self.a = a
        self.b = b

# Pairs slice to represent a slice of Pair
class Pairs:
    def __init__(self, a):
        self.a = a

    def __len__(self):
        return len(self.a)

    def __getitem__(self, i):
        return self.a[i]

    def __setitem__(self, i, v):
        self.a[i] = v

    def __delitem__(self, i):
        del self.a[i]

    def __iter__(self):
        return iter(self.a)

    def __reversed__(self):
        return reversed(self.a)

    def append(self, v):
        self.a.append(v)

    def clear(self):
        self.a.clear()

    def copy(self):
        return Pairs(self.a.copy())

    def count(self, v):
        return self.a.count(v)

    def extend(self, v):
        self.a.extend(v)

    def index(self, v, start=0, end=None):
        return self.a.index(v, start, end)

    def insert(self, i, v):
        self.a.insert(i, v)

    def pop(self, i=-1):
        return self.a.pop(i)

    def remove(self, v):
        self.a.remove(v)

    def reverse(self):
        self.a.reverse()

    def sort(self):
        self.a.sort()

# Variable to hold the nextReader function
nextReader = None

# Initializes the nextReader function
def init():
    global nextReader
    nextReader = NewScanner()

# NewScanner function to create a new scanner for reading input
def NewScanner():
    r = bufio.Scanner(sys.stdin)
    r.buffer(bytearray(1024), int(1e+11))
    r.split(bufio.ScanWords)
    return lambda: r.text()

# nextString function to read the next string
def nextString():
    return nextReader()

# nextInt64 function to read the next 64-bit integer
def nextInt64():
    v, _ = strconv.ParseInt(nextReader(), 10, 64)
    return v

# nextInt function to read the next integer
def nextInt():
    v, _ = strconv.Atoi(nextReader())
    return v

# nextInts function to read a slice of integers of length N
def nextInts(n):
    r = [0] * n
    for i in range(n):
        r[i] = nextInt()
    return r

# nextStrings function to read a slice of strings of length N
def nextStrings(n):
    r = [0] * n
    for i in range(n):
        r[i] = nextString()
    return r

# nextFloat64 function to read the next float64
def nextFloat64():
    f, _ = strconv.ParseFloat(nextReader(), 64)
    return f

