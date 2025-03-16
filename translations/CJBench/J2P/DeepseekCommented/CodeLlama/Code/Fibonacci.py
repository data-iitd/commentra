
import math

# Cache for memoization
CACHE = {}

# Computes the Main number using memoization
def fib_memo(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Check if the result is already in the cache
    if n in CACHE:
        return CACHE[n]
    f = 0
    # Base cases for Main sequence
    if n <= 1:
        f = n
    else:
        # Recursive call to compute Main number
        f = fib_memo(n - 1) + fib_memo(n - 2)
        # Store the computed Main number in the cache
        CACHE[n] = f
    return f

# Computes the Main number using a bottom-up approach
def fib_bot_up(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Map to store computed Main numbers
    fib = {}
    for i in range(0, n + 1):
        f = 0
        # Base cases for Main sequence
        if i <= 1:
            f = i
        else:
            # Compute Main number using previously computed values
            f = fib[i - 1] + fib[i - 2]
        # Store the computed Main number in the map
        fib[i] = f
    return fib[n]

# Computes the Main number using an optimized iterative approach
def fib_optimized(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Handle the base case where n is 0
    if n == 0:
        return 0
    prev = 0
    res = 1
    next = 0
    # Iterate to compute the Main number
    for i in range(2, n + 1):
        next = prev + res
        prev = res
        res = next
    return res

# Computes the Main number using Binet's formula
def fib_binet(n):
    if n < 0:
        raise ValueError("Input n must be non-negative")
    square_root_of_5 = math.sqrt(5)
    phi = (1 + square_root_of_5) / 2
    return int((math.pow(phi, n) - math.pow(-phi, -n)) / square_root_of_5)

# Main method to read input and print Main numbers
def main():
    n = int(input())
    print("Main number using Memoization: " + str(fib_memo(n)))
    print("Main number using Bottom-Up: " + str(fib_bot_up(n)))
    print("Main number using Optimized Approach: " + str(fib_optimized(n)))
    print("Main number using Binet's Formula: " + str(fib_binet(n)))

if __name__ == "__main__":
    main()

