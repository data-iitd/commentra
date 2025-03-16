import sys

# Class to perform operations in a modular arithmetic system
class RemRing:
    def __init__(self, module):
        self.module = module

    # Method to perform modular addition
    def sum(self, a, b):
        return (a + b + self.module) % self.module

    # Method to perform modular subtraction
    def sub(self, a, b):
        return (a - b + self.module) % self.module

    # Method to perform modular multiplication
    def prod(self, a, b):
        return (a * b) % self.module

    # Method to perform modular division
    def div(self, a, b):
        return (a * self.inv(b)) % self.module

    # Method to compute the modular inverse using the Extended Euclidean Algorithm
    def inv(self, a):
        b = self.module
        u = 1
        v = 0

        # Extended Euclidean Algorithm to find the inverse
        while b > 0:
            t = a / b
            a -= t * b
            u -= t * v
            z = a
            a = b
            b = z
            z = u
            u = v
            v = z

        # Ensure the result is positive
        u %= self.module
        if u < 0:
            u += self.module

        # Return the modular inverse
        return u

# Create a RemRing object to perform modular arithmetic operations
ring = RemRing(1000000007)

# Read a line of input from the user
s = sys.stdin.readline()

# Output the next character in the ASCII sequence of the first character of the input
print(chr(ord(s[0]) + 1), end='')

