
import sys

# I/O
sc = sys.stdin.readline

# Arithmetic
def max(nums):
    return max(nums)

def min(nums):
    return min(nums)

def abs(x):
    return abs(x)

def pow(x, y):
    return x ** y

# Sort
class Val:
    def __init__(self, id, num):
        self.id = id
        self.num = num

class ByNum(list):
    def __lt__(self, other):
        return self.num < other.num

# Read input values
A, B, C, K = map(int, sc().split())

# Determine the maximum value among A, B, and C
ma = max([A, B, C])

# Calculate the sum of the other two values
rest = 0
if ma == A:
    rest += B + C
elif ma == B:
    rest += A + C
else:
    rest += A + B

# Double the maximum value K times
for i in range(K):
    ma *= 2

# Print the final result
print(ma + rest)

