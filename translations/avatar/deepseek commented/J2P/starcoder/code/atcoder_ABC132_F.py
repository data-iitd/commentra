import sys

# Define the modulo constant
mod = 1000000007

# Define the main function
def main():
    # Read the input
    n = int(input())
    k = int(input())

    # Initialize the len list
    len = []
    l = 1
    while l <= n:
        r = n // (n // l)
        len.append(r - l + 1)
        l = r + 1

    # Store the size of the len list in q
    q = len(len)

    # Initialize the dp array with sufficient size
    dp = [0] * (k * (q + 1))

    # Calculate the prefix sums of the lengths and store them in the dp array
    for j in range(1, q + 1):
        dp[j] = len[j - 1] + dp[j - 1]
    for i in range(1, k):
        for j in range(1, q + 1):
            dp[i * (q + 1) + j] = (dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * len[j - 1]) % mod

    # Print the result stored in the dp array
    print(dp[k * (q + 1) - 1])

# Call the main function
if __name__ == '__main__':
    main()

