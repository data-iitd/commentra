import math

# Main function is the entry point of our program
def main():
    # Declare and initialize variables
    N, M = map(int, input().split())
    ans = 0

    # Check if N and M are equal to 1
    if N == 1 and M == 1:
        # If so, increment the ans variable
        ans += 1
    elif N > 1 and M > 1:
        # If N and M are greater than 1, calculate the area of the rectangle
        ans += (N - 2) * (M - 2)
    else:
        # If N or M is equal to 1, calculate the number of points on the edge
        ans += (N * M) - 2

    # Print the value of ans to the standard output
    print(ans)

# Helper functions
def max_value(*args):
    # Find the maximum value in the arguments
    return max(args)

def min_value(*args):
    # Find the minimum value in the arguments
    return min(args)

def pow_value(x, y):
    # Calculate x raised to the power of y
    return int(math.pow(x, y))

def abs_value(x):
    # Calculate the absolute value of x
    return abs(x)

def floor_value(x):
    # Round x down to the nearest integer
    return math.floor(x)

# Helper function for sorting a list of integers based on their absolute values
def sort_by_abs(arr):
    return sorted(arr, key=abs)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
