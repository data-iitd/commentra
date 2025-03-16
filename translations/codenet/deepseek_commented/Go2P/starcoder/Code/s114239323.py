# Reads the next integer from the input
def nextInt():
    return int(input()) # Comment: Reads the next integer from the input

# Reads a slice of integers of length N
def nextInts(N):
    return list(map(int, input().split())) # Comment: Reads a slice of integers of length N

# Main function to solve the problem
def main():
    # Reads the number of steps N
    N = nextInt() # Comment: Reads the number of steps N
    
    # Reads the list of heights h
    h = nextInts(N) # Comment: Reads the list of heights h
    
    # Initializes the DP array with zeros
    dp = [0] * N # Comment: Initializes the DP array with zeros
    for i in range(N):
        dp[i] = 0
    
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
class Pairs(list):
    def __init__(self, a):
        list.__init__(self, a)

    def Len(self):
        return len(self)

    def Swap(self, i, j):
        self[i], self[j] = self[j], self[i]

    def Less(self, i, j):
        return self[i].b < self[j].b

# Variable to hold the nextReader function
nextReader = None

# Initializes the nextReader function
def init():
    global nextReader
    nextReader = NewScanner()

# NewScanner function to create a new scanner for reading input
def NewScanner():
    r = bufio.NewScanner(sys.stdin)
    r.Buffer(make([]byte, 1024), int(1e+11))
    r.Split(bufio.ScanWords)
    return r.Scan

# nextString function to read the next string
def nextString():
    return nextReader()

# nextInt64 function to read the next 64-bit integer
def nextInt64():
    return int(nextReader())

# nextInt function to read the next integer
def nextInt():
    return int(nextReader())

# nextInts function to read a slice of integers of length N
def nextInts(n):
    r = []
    for i in range(n):
        r.append(int(nextReader()))
    return r

# nextStrings function to read a slice of strings of length N
def nextStrings(n):
    r = []
    for i in range(n):
        r.append(nextReader())
    return r

# nextFloat64 function to read the next float64
def nextFloat64():
    return float(nextReader())

