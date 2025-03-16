

def karatsuba(x, y):
    if max(x.bit_length(), y.bit_length()) <= 4:
        return x * y
    m = max(x.bit_length(), y.bit_length()) // 2
    high1 = x >> m
    low1 = x - (high1 << m)
    high2 = y >> m
    low2 = y - (high2 << m)
    z0 = karatsuba(low1, low2)
    z1 = karatsuba(low1 + high1, low2 + high2)
    z2 = karatsuba(high1, high2)
    return (z2 << (2 * m)) + ((z1 - z2 - z0) << m) + z0

if __name__ == "__main__":
    num1 = int(input("Enter the first number: "))
    num2 = int(input("Enter the second number: "))
    result = karatsuba(num1, num2)
    print("The product of the two numbers is:", result)

