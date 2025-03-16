import math
from functools import reduce
from operator import mul

# Function to calculate combination (n choose m) using integers for large numbers
def C(n, m):
    if n > m:
        return 0
    if n == 0 or n == m:
        return 1
    # Calculate product from m-n+1 to m
    numerator = reduce(mul, range(m - n + 1, m + 1), 1)
    # Divide by product from 1 to n
    denominator = reduce(mul, range(1, n + 1), 1)
    return numerator // denominator

def main():
    n, p = map(int, input().split())
    k0 = 0  # Count of even numbers
    k1 = 0  # Count of odd numbers

    # Count even and odd numbers in the input
    for _ in range(n):
        x = int(input())
        if x % 2 == 1:
            k1 += 1
        else:
            k0 += 1

    # Initialize result for number of ways to arrange items
    ans = 1

    # Calculate number of ways based on the value of p
    ans *= 2 ** k0  # Multiply by 2 for each even number

    if p == 0:
        add = 0
        # Sum combinations of odd numbers, taking 0, 2, 4, ... odd numbers
        for i in range(0, k1 + 1, 2):
            add += C(i, k1)
        ans *= add  # Multiply result by the sum
        print(ans)  # Print final result
    else:
        add = 0
        # Sum combinations of odd numbers, taking 1, 3, 5, ... odd numbers
        for i in range(1, k1 + 1, 2):
            add += C(i, k1)
        ans *= add  # Multiply result by the sum
        print(ans)  # Print final result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
