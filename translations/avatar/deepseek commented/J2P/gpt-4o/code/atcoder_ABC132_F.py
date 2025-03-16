import sys

def main():
    mod = int(1e9 + 7)  # Define the modulo constant
    n, k = map(int, sys.stdin.readline().split())  # Read the integers n and k from input

    lengths = []  # Create a list to store segment lengths
    l = 1  # Initialize the starting point of the segment
    while l <= n:
        r = n // (n // l)  # Calculate the ending point of the segment
        lengths.append(r - l + 1)  # Add the length of the segment to the list
        l = r + 1  # Move to the next segment

    q = len(lengths)  # Store the size of the lengths list in q
    dp = [0] * (k * (q + 1))  # Initialize the dp array with sufficient size

    # Calculate the prefix sums of the lengths and store them in the dp array
    for j in range(1, q + 1):
        dp[j] = lengths[j - 1] + dp[j - 1]

    # Main loop to calculate the dynamic programming values for k iterations
    for i in range(1, k):
        for j in range(1, q + 1):
            dp[i * (q + 1) + j] = (dp[i * (q + 1) + j - 1] + dp[(i - 1) * (q + 1) + q - j + 1] * lengths[j - 1]) % mod

    # Print the result stored in the dp array
    print(dp[k * (q + 1) - 1])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
