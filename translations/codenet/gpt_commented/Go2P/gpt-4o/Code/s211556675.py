import sys

# I/O
class Scanner:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next_str(self):
        result = self.data[self.index]
        self.index += 1
        return result

    def next_int(self):
        return int(self.next_str())

    def next_float(self):
        return float(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

# Arithmetic functions
def max_value(*nums):
    return max(nums)

def min_value(*nums):
    return min(nums)

def abs_value(x):
    return abs(x)

def pow_value(x, y):
    return x ** y

# Main function
def main():
    sc = Scanner()  # Create a new scanner for input

    # Read four integers from input
    A = sc.next_int()
    B = sc.next_int()
    C = sc.next_int()
    K = sc.next_int()

    # Determine the maximum value among A, B, and C
    ma = max_value(A, B, C)
    rest = 0  # Initialize the rest variable to hold the sum of the other two values

    # Calculate the sum of the two smaller values
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B

    # Double the maximum value K times
    for _ in range(K):
        ma *= 2

    # Output the final result: doubled max value plus the sum of the other two
    print(ma + rest)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
