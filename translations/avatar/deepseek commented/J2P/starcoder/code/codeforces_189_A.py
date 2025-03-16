
import sys

def main():
    # Read three integers from the user
    n = int(input())
    maxn = 4010
    a = int(input())
    b = int(input())
    c = int(input())

    # Store the coin values in an array
    arr = [a, b, c]

    # Initialize a dp array with all elements set to Integer.MIN_VALUE
    dp = [sys.maxsize] * maxn

    # Set the base case where dp[0] is 0
    dp[0] = 0

    # Iterate over the coin values and update the dp array
    for i in range(3):
        for j in range(arr[i], maxn):
            dp[j] = min(dp[j], dp[j - arr[i]] + 1)

    # Print the value of dp[n]
    print(dp[n])

if __name__ == '__main__':
    main()

