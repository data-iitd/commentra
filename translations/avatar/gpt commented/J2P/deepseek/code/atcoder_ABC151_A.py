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
            t = a // b
            a, b = b, a - t * b
            u, v = v, u - t * v

        # Ensure the result is positive
        u %= self.module
        if u < 0:
            u += self.module

        # Return the modular inverse
        return u

# Main function to read input and perform operations
def main():
    # Read a line of input from the user
    s = sys.stdin.readline().strip()

    # Output the next character in the ASCII sequence of the first character of the input
    next_char = chr(ord(s[0]) + 1)
    print(next_char)

# Call the main function
if __name__ == "__main__":
    main()
