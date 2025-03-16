# Define a constant for the modulo operation
MOD = 1000000007

def main():
    # Read the total number of elements (n) and the number of blocked positions (p) from input
    n, p = map(int, input().split())

    # Create a set to store the blocked positions
    blocked_positions = set()
    
    # Read the blocked positions and store them in the set
    for _ in range(p):
        n1 = int(input())
        blocked_positions.add(n1)

    # Initialize a list to store the number of ways to reach each position
    dp = [0] * (n + 1)
    
    # Base cases: There is 1 way to reach the 0th and 1st positions
    dp[0] = 1
    dp[1] = 1

    # If the first position is blocked, set the number of ways to reach it to 0
    if 1 in blocked_positions:
        dp[1] = 0

    # Iterate through positions from 2 to n to calculate the number of ways to reach each position
    for i in range(2, n + 1):
        # If the current position is blocked, skip the calculation
        if i in blocked_positions:
            continue
        # Calculate the number of ways to reach the current position using the previous two positions
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD

    # Print the number of ways to reach the nth position
    print(dp[n])

# Call the main function
main()
