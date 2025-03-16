import sys

class Main:
    @staticmethod
    def karatsuba(x, y):
        # Base case: if either x or y is less than or equal to 15,
        # return the product of x and y using the built-in multiplication method
        if x.bit_length() <= 15 or y.bit_length() <= 15:
            return x * y

        # Calculate the maximum bit length of x and y and divide it by 2 to get m
        n = max(x.bit_length(), y.bit_length())
        m = n // 2

        # Shift right x by m bits to get the high part (the left half)
        high1 = x >> m

        # Subtract the shifted high part from x and shift left m bits to get the low part (the right half)
        low1 = x - (high1 << m)

        # Perform the same operations on y
        high2 = y >> m
        low2 = y - (high2 << m)

        # Recursively calculate the product of the low parts using the karatsuba method
        z0 = Main.karatsuba(low1, low2)

        # Calculate the product of the high parts and shift left 2m bits to get z2
        z2 = Main.karatsuba(high1, high2) << (2 * m