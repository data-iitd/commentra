import sys

# Function to read the next word from the input
def get_next_word():
    return input().strip()

# Function to read the next integer from the input
def get_next_int():
    return int(get_next_word())

def main():
    # Read the first two integers, n and m, from the input
    n = get_next_int()
    m = get_next_int()

    # Initialize a set to store the blocked positions
    blocked_positions = set()
    for _ in range(m):
        blocked_positions.add(get_next_int())

    # Create a dynamic programming array to store the number of ways to reach each position
    dp = [0] * (n + 1)
    dp[0] = 1  # Base case: There is one way to be at the starting position (doing nothing)

    # Iterate through each position from 0 to n
    for i in range(n):
        # Check the next two positions (i+1 and i+2) to see if they can be reached
        for ii in range(1, 3):
            if i + ii <= n and (i + ii) not in blocked_positions:
                # Update the number of ways to reach position i+ii based on the current position i
                dp[i + ii] += dp[i]
                dp[i + ii] %= 1000000007  # Ensure the result stays within the modulo limit

    # Output the total number of ways to reach position n
    print(dp[n])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
