import sys
from functools import reduce

# FastReader class to handle fast input
class FastReader:
    def __init__(self):
        self.input = sys.stdin.read
        self.data = self.input().split()
        self.index = 0

    def next(self):
        if self.index < len(self.data):
            result = self.data[self.index]
            self.index += 1
            return result
        return None

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_line(self):
        return ' '.join(self.data[self.index:])

# Method to compute (x^y) % mod using modular exponentiation
def mod_power(x, y, mod):
    res = 1
    x %= mod  # Reduce x modulo mod
    if x == 0:
        return 0  # If x is 0, return 0

    # Loop until y becomes 0
    while y > 0:
        # If y is odd, multiply x with result
        if y % 2 == 1:
            res = (res * x) % mod
        y //= 2  # Divide y by 2
        x = (x * x) % mod  # Square x
    return res  # Return the final result

# Main method to execute the program
if __name__ == "__main__":
    in_reader = FastReader()  # Create an instance of FastReader
    a = [0] * 4  # Array to hold four long integers

    # Read four long integers from input
    for i in range(4):
        a[i] = in_reader.next_long()

    # Calculate and print the maximum product of pairs from the array
    print(max(a[0] * a[2], 
               max(a[1] * a[3], 
                   max(a[0] * a[3], a[1] * a[2]))))

# <END-OF-CODE>
