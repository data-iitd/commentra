
import sys
import math

def solve():
    # Read the number of elements
    n = int(sys.stdin.readline())
    # Read the integer slice of size n
    as = [int(x) for x in sys.stdin.readline().split()]

    # Create a new slice to store adjusted values
    xs = [0] * n
    for i, a in enumerate(as):
        # Adjust each element by subtracting its index and adding 1
        xs[i] = a - i + 1
    # Sort the adjusted values
    xs.sort()

    # Find the median value from the sorted slice
    b = xs[n // 2]
    ans = 0
    # Calculate the total distance from each element to the median
    for x in xs:
        ans += abs(x - b)
    # Output the result
    print(ans)

# abs function returns the absolute value of an integer
def abs(n):
    if n < 0:
        return -n
    return n

# -----------------------------------------

# main function initializes input/output and calls the solve function
def main():
    # Call the solve function to perform the main logic
    solve()

# -----------------------------------------

if __name__ == '__main__':
    main()

