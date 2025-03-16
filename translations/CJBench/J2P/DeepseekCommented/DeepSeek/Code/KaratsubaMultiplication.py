import math
from typing import Final

class Main:
    __slots__ = ()

    @staticmethod
    def karatsuba(x: int, y: int) -> int:
        # Base case: if the numbers are small enough, use simple multiplication
        if x < 10 or y < 10:
            return x * y

        # Determine the size of the numbers
        n = max(len(str(x)), len(str(y)))
        m = n // 2

        # Split the numbers into high and low parts
        high1 = x // (10 ** m)
        low1 = x % (10 ** m)
        high2 = y // (10 ** m)
        low2 = y % (10 ** m)

        # Recursively compute the three multiplications
        z0 = Main.karatsuba(low1, low2)
        z1 = Main.karatsuba(low1 + high1, low2 + high2)
        z2 = Main.karatsuba(high1, high2)

        # Combine the results using the Karatsuba formula
        return (z2 * (10 ** (2 * m))) + ((z1 - z2 - z0) * (10 ** m)) + z0

    @staticmethod
    def main():
        try:
            # Read two large integers from the user
            num1 = int(input().strip())
            num2 = int(input().strip())

            # Compute the product using the Karatsuba algorithm
            result = Main.karatsuba(num1, num2)

            # Print the result
            print("The product of the two numbers is:")
            print(result)
        except ValueError:
            # Handle invalid input
            print("Invalid input. Please enter valid large numbers.")

Main.main()
