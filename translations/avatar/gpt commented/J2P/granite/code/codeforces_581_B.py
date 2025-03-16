
import sys

def main():
    # Read the number of elements
    n = int(input())

    # Populate the array with input values
    a = list(map(int, input().split()))

    # Initialize a dp array to store the maximum values
    dp = [0] * (n + 1)

    # Fill the dp array with -1 to indicate uninitialized values
    for i in range(n - 1, -1, -1):
        dp[i] = max(dp[i + 1], a[i])

    # Iterate through the original array to calculate the output
    for i in range(n):
        # If the current element is greater than the next maximum, print 0
        if a[i] > dp[i + 1]:
            print(0, end=' ')
        # Otherwise, calculate and print the difference to the next maximum
        else:
            print(dp[i + 1] - a[i] + 1, end=' ')

    # Print a new line after all outputs
    print()

if __name__ == "__main__":
    main()

