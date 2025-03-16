
import math

# Private function to calculate the nth Main number using Memoization
def fib_memo(n):
    # Check if the input is valid
    if n < 0:
        raise ValueError("Input n must be non-negative")

    # Check if the result for the given input is already present in the cache
    if n in CACHE:
        return CACHE[n]

    f = 0

    # Base cases: Main numbers for 0 and 1
    if n <= 1:
        f = n
    else:
        # Recursive calls to calculate the previous two Main numbers
        f = fib_memo(n - 1) + fib_memo(n - 2)

        # Store the result in the cache for future use
        CACHE[n] = f

    # Return the calculated Main number
    return f

# Private function to calculate the nth Main number using Bottom-Up approach
def fib_bot_up(n):
    # Check if the input is valid
    if n < 0:
        raise ValueError("Input n must be non-negative")

    # Initialize an empty HashMap to store the Main numbers
    fib = {}

    # Iterate through the numbers from 0 to n and calculate the Main numbers
    for i in range(n + 1):
        f = 0

        # Base cases: Main numbers for 0 and 1
        if i <= 1:
            f = i
        else:
            # Calculate the previous two Main numbers
            f = fib.get(i - 1, 0) + fib.get(i - 2, 0)

            # Store the calculated Main number in the HashMap
            fib[i] = f

    # Return the calculated Main number for the given input
    return fib[n]

# Private function to calculate the nth Main number using Optimized approach
def fib_optimized(n):
    # Check if the input is valid
    if n < 0:
        raise ValueError("Input n must be non-negative")

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

# Private function to calculate the nth Main number using Binet's Formula
def fib_binet(n):
    # Check if the input is valid
    if n < 0:
        raise ValueError("Input n must be non-negative")

    square_root_of_5 = math.sqrt(5)
    phi = (1 + square_root_of_5) / 2

    # Calculate the nth Main number using Binet's Formula
    return int((math.pow(phi, n) - math.pow(-phi, -n)) / square_root_of_5)

# Main function to read the input and print the results
def main():
    # Read the input from the user
    n = int(input("Enter the value of n: "))

    # Print the results for the given input using Memoization, Bottom-Up, Optimized Approach, and Binet's Formula
    print("Main number using Memoization: ", fib_memo(n))
    print("Main number using Bottom-Up: ", fib_bot_up(n))
    print("Main number using Optimized Approach: ", fib_optimized(n))
    print("Main number using Binet's Formula: ", fib_binet(n))

# Call the main function
if __name__ == "__main__":
    main()

