import math

class Karatsuba:
    @staticmethod
    def karatsuba(x, y):
        # Base case: when numbers are small enough, use direct multiplication
        # If the number is 4 bits or smaller, switch to the classical method
        if x.bit_length() <= 4 or y.bit_length() <= 4:
            return x * y

        # Find the maximum bit length of the two numbers
        n = max(x.bit_length(), y.bit_length())

        # Split the numbers in the middle
        m = n // 2

        # High and low parts of the first number x (x = a * 10^m + b)
        high1 = x >> m  # a = x // 2^m (higher part)
        low1 = x - (high1 << m)  # b = x - a * 2^m (lower part)

        # High and low parts of the second number y (y = c * 10^m + d)
        high2 = y >> m  # c = y // 2^m (higher part)
        low2 = y - (high2 << m)  # d = y - c * 2^m (lower part)

        # Recursively calculate three products
        z0 = Karatsuba.karatsuba(low1, low2)  # z0 = b * d (low1 * low2)
        z1 = Karatsuba.karatsuba(low1 + high1, low2 + high2)  # z1 = (a + b) * (c + d)
        z2 = Karatsuba.karatsuba(high1, high2)  # z2 = a * c (high1 * high2)

        # Combine the results using Karatsuba's formula
        return (z2 << (2 * m)) + ((z1 - z2 - z0) << m) + z0  # z2 * 10^(2*m) + (z1 - z2 - z0) * 10^m + z0

if __name__ == "__main__":
    try:
        num1 = int(input("Enter the first large number: ").strip())
        num2 = int(input("Enter the second large number: ").strip())

        result = Karatsuba.karatsuba(num1, num2)

        print("The product of the two numbers is:")
        print(result)
    except ValueError:
        print("Invalid input. Please enter valid large numbers.")
