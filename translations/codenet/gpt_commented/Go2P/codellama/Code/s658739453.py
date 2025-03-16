
# Define a constant for the modulo operation
d = 1000000007

# Define a function to calculate the number of ways to reach each position
def calculate_ways(n, p, mdans):
    # Initialize a list to store the number of ways to reach each position
    dp = [0] * (n + 1)

    # Base cases: There is 1 way to reach the 0th and 1st positions
    dp[0] = 1
    dp[1] = 1

    # If the first position is blocked, set the number of ways to reach it to 0
    if 1 in mdans:
        dp[1] = 0

    # Iterate through positions from 2 to n to calculate the number of ways to reach each position
    for i in range(2, n + 1):
        # If the current position is blocked, skip the calculation
        if i in mdans:
            continue
        # Calculate the number of ways to reach the current position using the previous two positions
        dp[i] = (dp[i - 1] + dp[i - 2]) % d

    # Return the number of ways to reach the nth position
    return dp[n]

# Read the total number of elements (n) and the number of blocked positions (p) from input
n, p = map(int, input().split())

# Read the blocked positions and store them in a set
mdans = set(map(int, input().split()))

# Calculate the number of ways to reach the nth position
result = calculate_ways(n, p, mdans)

# Print the number of ways to reach the nth position
print(result)

