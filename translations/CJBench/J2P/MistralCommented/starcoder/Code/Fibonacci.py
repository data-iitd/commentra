import sys

# Declare a static final Map to store the Main numbers for memoization
CACHE = {}

# Memoization method to calculate the nth Main number
def fibMemo(n):
    # Check if the input is valid
    if n < 0:
        raise Exception("Input n must be non-negative")

    # Check if the result for the given input is already present in the cache
    if n in CACHE:
        return CACHE[n]

    f = 0

    # Base cases: Main numbers for 0 and 1
    if n <= 1:
        f = n
    else:
        # Recursive calls to calculate the previous two Main numbers
        f = fibMemo(n - 1) + fibMemo(n - 2)

        # Store the result in the cache for future use
        CACHE[n] = f

    # Return the calculated Main number
    return f

# Bottom-Up method to calculate the nth Main number
def fibBotUp(n):
    # Check if the input is valid
    if n < 0:
        raise Exception("Input n must be non-negative")

    # Initialize an empty HashMap to store the Main numbers
    fib = {}

    # Iterate through the numbers from 0 to n and calculate the Main numbers
    for i in range(0, n + 1):
        f = 0

        # Base cases: Main numbers for 0 and 1
        if i <= 1:
            f = i
        else:
            # Calculate the previous two Main numbers
            f = fib.get(i - 1) + fib.get(i - 2)

            # Store the calculated Main number in the HashMap
            fib[i] = f

    # Return the calculated Main number for the given input
    return fib.get(n)

# Optimized method to calculate the nth Main number using O(1) space complexity
def fibOptimized(n):
    # Check if the input is valid
    if n < 0:
        raise Exception("Input n must be non-negative")

    if n == 0:
        # Base case: Main number for 0 is 0
        return 0

    prev = 0
    res = 1
    next = 0

    # Iterate through the numbers from 2 to n and calculate the Main numbers
    for i in range(2, n + 1):
        next = prev + res
        prev = res
        res = next

    # Return the calculated Main number for the given input
    return res

# Method to calculate the nth Main number using Binet's Formula
def fibBinet(n):
    # Check if the input is valid
    if n < 0:
        raise Exception("Input n must be non-negative")

    squareRootOf5 = pow(5, 0.5)
    phi = (1 + squareRootOf5) / 2

    # Calculate the nth Main number using Binet's Formula
    return int((pow(phi, n) - pow(-phi, -n)) / squareRootOf5)

# Main method to read the input and print the results
def main():
    # Read the input from the user
    n = int(input())

    # Print the results for the given input using Memoization, Bottom-Up, Optimized Approach, and Binet's Formula
    print("Main number using Memoization: " + str(fibMemo(n)))
    print("Main number using Bottom-Up: " + str(fibBotUp(n)))
    print("Main number using Optimized Approach: " + str(fibOptimized(n)))
    print("Main number using Binet's Formula: " + str(fibBinet(n)))

# Entry point of the program
if __name__ == "__main__":
    main()

# 