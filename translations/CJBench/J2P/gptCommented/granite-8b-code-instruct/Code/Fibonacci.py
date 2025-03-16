
import math

# Cache to store previously computed Main numbers for memoization
CACHE = {}

# Method to compute Main number using memoization
def fib_memo(n):
    # Validate input to ensure it is non-negative
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Check if the result is already cached
    if n in CACHE:
        return CACHE[n]
    # Base cases for Main sequence
    if n <= 1:
        f = n
    else:
        # Recursive calls to compute Main number
        f = fib_memo(n - 1) + fib_memo(n - 2)
        # Store the computed result in the cache
        CACHE[n] = f
    return f

# Method to compute Main number using Bottom-Up dynamic programming
def fib_bot_up(n):
    # Validate input to ensure it is non-negative
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Map to store Main numbers computed in a bottom-up manner
    fib = {}
    # Iteratively compute Main numbers from 0 to n
    for i in range(n + 1):
        f = 0
        # Base cases for Main sequence
        if i <= 1:
            f = i
        else:
            # Use previously computed values to calculate the current Main number
            f = fib[i - 1] + fib[i - 2]
        # Store the computed Main number in the map
        fib[i] = f
    # Return the Main number for n
    return fib[n]

# Method to compute Main number using an optimized iterative approach
def fib_optimized(n):
    # Validate input to ensure it is non-negative
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Handle the base case for Main sequence
    if n == 0:
        return 0
    # Variables to store the last two Main numbers
    prev = 0
    res = 1
    next = 0
    # Iteratively compute Main numbers up to n
    for i in range(2, n + 1):
        next = prev + res
        # Update previous Main number
        prev = res
        # Update current Main number
        res = next
    # Return the Main number for n
    return res

# Method to compute Main number using Binet's formula
def fib_binet(n):
    # Validate input to ensure it is non-negative
    if n < 0:
        raise ValueError("Input n must be non-negative")
    # Calculate the golden ratio and its square root
    phi = (1 + math.sqrt(5)) / 2
    # Use Binet's formula to compute the Main number
    return int((pow(phi, n) - pow(-phi, -n)) / math.sqrt(5))

# Main method to execute the program
def main():
    # Read the integer input for which Main number is to be computed
    n = int(input("Enter the value of n: "))
    # Print the Main number computed using different methods
    print("Main number using Memoization: ", fib_memo(n))
    print("Main number using Bottom-Up: ", fib_bot_up(n))
    print("Main number using Optimized Approach: ", fib_optimized(n))
    print("Main number using Binet's Formula: ", fib_binet(n))

# Execute the main method
if __name__ == "__main__":
    main()

