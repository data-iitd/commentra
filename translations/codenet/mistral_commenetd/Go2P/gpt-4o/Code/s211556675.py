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

    def next_rune_slice(self):
        return list(self.next_str())

    def next_int_slice(self, n):
        return [self.next_int() for _ in range(n)]

    def next_float_slice(self, n):
        return [self.next_float() for _ in range(n)]

# Arithmetic
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
    sc = Scanner()  # Initialize a new Scanner

    # Read input values
    A = sc.next_int()
    B = sc.next_int()
    C = sc.next_int()
    K = sc.next_int()

    # Find the maximum value among A, B, and C
    ma = max_value(A, B, C)

    # Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
    rest = 0
    if ma == A:
        rest += B + C
    elif ma == B:
        rest += A + C
    else:
        rest += A + B

    # Calculate the final answer
    answer = pow_value(ma, K) + rest

    # Write the answer to the output
    print(answer)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
