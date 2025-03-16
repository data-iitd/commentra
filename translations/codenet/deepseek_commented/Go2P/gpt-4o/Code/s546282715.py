import sys

# Function to read the next word from the input
def get_next_word():
    return input().strip()

# Function to read the next integer from the input
def get_next_int():
    return int(get_next_word())

# Main function starts here
def main():
    # Determine the input source based on command-line arguments
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as f:
            input_data = f.read().splitlines()
            input_iter = iter(input_data)
            input = lambda: next(input_iter)
    else:
        input = sys.stdin.read

    # Read the number of elements (n) and the number of restricted positions (m)
    n = get_next_int()
    m = get_next_int()

    # Create a set to store the restricted positions
    restricted_positions = set()
    for _ in range(m):
        restricted_positions.add(get_next_int())

    # Initialize the dynamic programming array
    dp = [0] * (n + 1)
    dp[0] = 1

    # Fill the dynamic programming array based on restricted positions
    for i in range(n):
        for ii in range(1, 3):
            if i + ii <= n and (i + ii) not in restricted_positions:
                dp[i + ii] = (dp[i + ii] + dp[i]) % 1000000007

    # Print the result
    print(dp[n])

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
