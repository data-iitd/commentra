
import sys

# Cache for memoization
CACHE = {}

# Computes the Main number using memoization
def fibMemo(n):
    if n < 0:
        raise Exception("Input n must be non-negative")
    # Check if the result is already in the cache
    if n in CACHE:
        return CACHE[n]
    f = 0
    # Base cases for Main sequence
    if n <= 1:
        f = n
    else:
        # Recursive call to compute Main number
        f = fibMemo(n - 1) + fibMemo(n - 2)
        # Store the computed Main number in the cache
        CACHE[n] = f
    return f

# Computes the Main number using a bottom-up approach
def fibBotUp(n):
    if n < 0:
        raise Exception("Input n must be non-negative")
    # Map to store computed Main numbers
    fib = {}
    for i in range(0, n + 1):
        f = 0
        # Base cases for Main sequence
        if i <= 1:
            f = i
        else:
            # Compute Main number using previously computed values
            f = fib.get(i - 1) + fib.get(i - 2)
        # Store the computed Main number in the map
        fib[i] = f
    return fib.get(n)

# Computes the Main number using an optimized iterative approach
def fibOptimized(n):
    if n < 0:
        raise Exception("Input n must be non-negative")
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
def fibBinet(n):
    if n < 0:
        raise Exception("Input n must be non-negative")
    squareRootOf5 = pow(5, 0.5)
    phi = (1 + squareRootOf5) / 2
    return int((pow(phi, n) - pow(-phi, -n)) / squareRootOf5)

# Main method to read input and print Main numbers
def main():
    n = int(sys.stdin.readline().strip())
    print("Main number using Memoization: " + str(fibMemo(n)))
    print("Main number using Bottom-Up: " + str(fibBotUp(n)))
    print("Main number using Optimized Approach: " + str(fibOptimized(n)))
    print("Main number using Binet's Formula: " + str(fibBinet(n)))

if __name__ == "__main__":
    main()

