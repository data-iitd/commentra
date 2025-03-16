# Read two integers from input: n (the total number) and k (the divisor)
n, k = map(int, input().split())

# Check if k is an odd number
if k % 2 == 1:
    # If k is odd, calculate the cube of the integer division of n by k
    print((n // k) ** 3)
else:
    # If k is even, calculate the sum of two cubes:
    # 1. The cube of the integer division of n by k
    # 2. The cube of the integer division of (n + k/2) by k
    print((n // k) ** 3 + ((n + k // 2) // k) ** 3)
