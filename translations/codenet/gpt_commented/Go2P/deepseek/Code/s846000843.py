import sys
import math
from itertools import accumulate

def main():
    # Initialize input/output handling
    io = Io()
    
    # Read the number of elements
    n = io.int()
    
    # Create a list to hold the input integers
    aa = [io.int() for _ in range(n)]
    
    # Compute the cumulative sum of the input integers
    cumsum = list(accumulate(aa))
    
    # Initialize the answer with a large value
    ans = 2020202020
    
    # Iterate through the cumulative sums to find the minimum difference
    for i in range(1, len(cumsum) - 1):
        ans = min(ans, abs(cumsum[-1] - cumsum[i] - (cumsum[i] - cumsum[0])))
    
    # Output the final answer
    print(ans)

class Io:
    def __init__(self):
        self.reader = sys.stdin
        self.writer = sys.stdout
        self.tokens = []
        self.nextToken = 0
    
    def flush(self):
        pass
    
    def next_line(self):
        return self.reader.readline().strip()
    
    def next(self):
        while self.nextToken >= len(self.tokens):
            line = self.next_line()
            self.tokens = line.split()
            self.nextToken = 0
        r = self.tokens[self.nextToken]
        self.nextToken += 1
        return r
    
    def int(self):
        return int(self.next())
    
    def float(self):
        return float(self.next())
    
    def print_ln(self, *args):
        print(*args, file=self.writer)
    
    def print_int_ln(self, a):
        self.print_ln(a)
    
    def print_string_ln(self, a):
        self.print_ln(a)

# Helper functions
def abs(a):
    return a if a >= 0 else -a

def pow(p, q):
    return int(math.pow(p, q))

def min(*nums):
    return min(nums)

def max(*nums):
    return max(nums)

def sort_asc(a):
    return sorted(a)

def sort_desc(a):
    return sorted(a, reverse=True)

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

# <END-OF-CODE>