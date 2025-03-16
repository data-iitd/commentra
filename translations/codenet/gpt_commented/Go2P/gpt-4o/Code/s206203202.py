def abs_value(x):
    """Returns the absolute value of an integer x."""
    if x < 0:
        return -x  # If x is negative, return its negation.
    return x  # If x is non-negative, return x itself.

def min_value(a, b):
    """Returns the smaller of two integers a and b."""
    if a > b:
        return b  # If a is greater than b, return b.
    return a  # Otherwise, return a.

def main():
    # Read two integers N and K from standard input.
    N, K = map(int, input().split())

    # The following block is commented out; it appears to be an alternative approach
    # to find a minimum value based on some conditions involving N and K.
    """
    seen = set()  # Create a set to track seen values of N.
    while True:
        if N not in seen:  # If N has not been seen before,
            seen.add(N)  # mark it as seen.
            N = abs_value(N - K)  # Update N to the absolute difference of N and K.
        else:
            break  # If N has been seen, exit the loop.
    
    mini = float('inf')  # Initialize mini to a large value.
    for k in seen:  # Iterate over the keys in the set.
        mini = min_value(mini, k)  # Update mini to the minimum value found.
    print(mini)  # Print the minimum value found.
    """

    # Calculate the remainder of N divided by K.
    x = N % K
    # Determine the minimum between the absolute difference of (x - K) and x.
    x = min_value(abs_value(x - K), x)
    # Print the final result.
    print(x)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
