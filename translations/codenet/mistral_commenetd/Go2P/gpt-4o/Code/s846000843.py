import sys
import math
from collections import defaultdict

# The main function is the entry point of the program.
def main():
    # Read the number n from the standard input.
    n = int(sys.stdin.readline().strip())

    # Initialize an array aa to store the input integers.
    aa = list(map(int, sys.stdin.readline().strip().split()))

    # Compute the cumulative sum of the aa array using the CumSum function.
    cumsum = CumSum(aa)

    # Initialize a variable ans to store the answer.
    ans = 2020202020

    # Use a for loop to iterate through the cumulative sum array, excluding the first and last elements.
    for i in range(1, len(cumsum) - 1):
        # Compute the absolute difference between the last cumulative sum and the current cumulative sum.
        diff1 = abs(cumsum[-1] - cumsum[i])

        # Compute the difference between the current cumulative sum and the first cumulative sum.
        diff2 = cumsum[i] - cumsum[0]

        # Keep the minimum of these two differences as the answer.
        ans = min(ans, diff1, diff2)

    # Print the answer.
    print(ans)

# The CumSum function computes the cumulative sum of an integer list.
def CumSum(nums):
    sums = [0]
    for num in nums:
        sums.append(sums[-1] + num)
    return sums

# The Abs function returns the absolute value of an integer.
def Abs(a):
    return a if a >= 0 else -a

# The Min function returns the minimum of a list of integers.
def Min(*nums):
    if len(nums) == 0:
        raise ValueError("function min() requires at least one argument.")
    return min(nums)

# The Max function returns the maximum of a list of integers.
def Max(*nums):
    if len(nums) == 0:
        raise ValueError("function max() requires at least one argument.")
    return max(nums)

# The GCD function returns the greatest common divisor of a and b.
def GCD(a, b):
    while b:
        a, b = b, a % b
    return a

# The LCM function returns the least common multiple of a and b.
def LCM(a, b):
    if a == 0 and b == 0:
        return 0
    return a * b // GCD(a, b)

# The Fact function returns the factorial of n.
def Fact(n):
    if n == 0:
        return 1
    else:
        return n * Fact(n - 1)

# The Divisors function returns all divisors of n.
def Divisors(n):
    divisors = set()
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)
    return sorted(divisors)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
