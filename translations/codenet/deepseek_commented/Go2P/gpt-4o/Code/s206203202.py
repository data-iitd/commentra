def abs_value(x):
    """Returns the absolute value of an integer."""
    return -x if x < 0 else x

def min_value(a, b):
    """Returns the smaller of two integers."""
    return b if a > b else a

def main():
    N, K = map(int, input().split())  # Read two integers from input

    x = N % K  # Calculate the remainder of N divided by K

    x = min_value(abs_value(x - K), x)  # Calculate the minimum of the absolute difference and x itself
    print(x)  # Print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
