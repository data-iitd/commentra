
import sys

# 最小公倍数
# Computes the greatest common divisor of two numbers x and y
def gcd(x, y):
    tmp = 0
    if x < y:
        tmp = x
        x = y
        y = tmp
    while y > 0:
        r = x % y
        x = y
        y = r
    return x

# 最大公倍数
# Computes the least common multiple of two numbers x and y
def lcm(x, y):
    return x // gcd(x, y) * y

# 階乗
# Computes the factorial of a number k modulo 10^9 + 7
def kaijo(k):
    sum = 1
    for i in range(1, k + 1):
        sum *= i
        sum %= 1000000000 + 7
    return sum

# for i in range(, ):

# Utility functions to find the maximum and minimum of two numbers
def lmax(s, t):
    if s > t:
        return s
    else:
        return t

def lmin(s, t):
    if s < t:
        return s
    else:
        return t

# ここから開始

# Read two integers n and k
n, k = map(int, sys.stdin.readline().split())
sum = 0

# Iterate over possible values of b
for b in range(1, n + 1):
    # Calculate the count and remainder
    cnt = (n + 1) // b
    md = (n + 1) % b

    # Update the sum based on the conditions involving k
    sum += cnt * max(b - k, 0) + max(md - k, 0)

    # Adjust the sum if k is 0
    if k == 0:
        sum -= 1

# Print the computed sum
print(sum)

