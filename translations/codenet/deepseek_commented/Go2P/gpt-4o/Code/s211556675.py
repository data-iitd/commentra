import sys

# I/O
class Scanner:
    def __init__(self):
        self.sc = sys.stdin.read().split()

    def next_str(self):
        return self.sc.pop(0)

    def next_int(self):
        return int(self.next_str())

    def next_float(self):
        return float(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

# Arithmetic
def max_value(*nums):
    return max(nums)

def min_value(*nums):
    return min(nums)

def abs_value(x):
    return abs(x)

def pow_value(x, y):
    return x ** y

def main():
    sc = Scanner()
    
    # Read input values
    A = sc.next_int()
    B = sc.next_int()
    C = sc.next_int()
    K = sc.next_int()
    
    # Determine the maximum value among A, B, and C
    ma = max_value(A, B, C)
    
    # Calculate the sum of the other two values
    rest = 0
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B
    
    # Double the maximum value K times
    for _ in range(K):
        ma *= 2
    
    # Print the final result
    print(ma + rest)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
