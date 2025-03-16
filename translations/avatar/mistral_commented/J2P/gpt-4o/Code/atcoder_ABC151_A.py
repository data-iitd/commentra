import sys  # Import sys module for reading input from standard input

class RemRing:  # Define a new class named RemRing
    def __init__(self, module):  # Constructor to initialize the module variable
        self.module = module

    def sum(self, a, b):  # Method to compute the sum of two numbers modulo the module
        return (a + b + self.module) % self.module

    def sub(self, a, b):  # Method to compute the difference of two numbers modulo the module
        return (a - b + self.module) % self.module

    def prod(self, a, b):  # Method to compute the product of two numbers modulo the module
        return (a * b) % self.module

    def div(self, a, b):  # Method to compute the quotient and remainder of two numbers modulo the module
        quotient = a * self.inv(b)  # Compute the quotient by multiplying the dividend with the multiplicative inverse of the divisor
        return quotient % self.module  # Return the quotient modulo the module

    def inv(self, a):  # Method to compute the multiplicative inverse of a number modulo the module
        b = self.module  # Initialize b as the module
        u = 1  # Initialize u as 1
        v = 0  # Initialize v as 0

        # Perform extended Euclidean algorithm to find the multiplicative inverse of a modulo the module
        while b > 0:
            t = a // b  # Compute the quotient of a divided by b
            z = a  # Store a temporarily
            a = b  # Update a with the value of b
            b = z % b  # Update b with the remainder of z modulo the module
            temp = u  # Store u temporarily
            u = v  # Update u with the value of v
            v = temp - t * v  # Update v as (u - t * v) % module

        # If the result is negative, add the module to make it positive
        if u < 0:
            u += self.module

        return u  # Return the multiplicative inverse of a

# Main execution
if __name__ == "__main__":
    s = sys.stdin.readline().strip()  # Read a line of input
    print(chr(ord(s[0]) + 1), end='')  # Print the ASCII value of the first character incremented by 1

# <END-OF-CODE>
