import sys

def karatsuba(x, y):
    if x.bit_length() <= 4 or y.bit_length() <= 4:
        return x * y
    n = max(x.bit_length(), y.bit_length())
    m = n // 2
    high1 = x >> m
    low1 = x - (high1 << m)
    high2 = y >> m
    low2 = y - (high2 << m)
    z0 = karatsuba(low1, low2)
    z1 = karatsuba(low1 + high1, low2 + high2)
    z2 = karatsuba(high1, high2)
    return (z2 << (2 * m)) + ((z1 - z2 - z0) << m) + z0

if __name__ == "__main__":
    try:
        num1 = int(input().strip())
        num2 = int(input().strip())
        result = karatsuba(num1, num2)
        print("The product of the two numbers is:")
        print(result)
    except ValueError:
        print("Invalid input. Please enter valid large numbers.", file=sys.stderr)

# <END-OF-CODE>
