import sys

# Function to read the next word from the input
def get_next_word():
    return input().strip()

# Function to read the next integer from the input
def get_next_int():
    return int(get_next_word())

# Main function
def main():
    # Open the standard input file if the command line argument is provided
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'r') as f:
            input = f.read
    else:
        input = sys.stdin.read

    # Read the first two integers from the input
    data = input().split()
    n = int(data[0])
    m = int(data[1])

    # Initialize an associative array to store the elements
    aa = set()
    # Read m elements and store them in the associative array
    for i in range(m):
        aa.add(int(data[2 + i]))

    # Initialize a list of length n+1 for dynamic programming
    dp = [0] * (n + 1)
    # Initialize the first element of the list
    dp[0] = 1

    # Iterate through the array from index 0 to n-1
    for i in range(n):
        # Iterate through the prefix sum from i to i+2
        for ii in range(1, 3):
            if i + ii <= n:
                # Skip if the current index and its sum are already present in the associative array
                if (i + ii) in aa:
                    continue
                # Calculate the dynamic programming value for the current index
                dp[i + ii] += dp[i]
                # Perform modulo operation to keep the value within the range of 10^9+7
                dp[i + ii] %= 1000000007

    # Print the final answer
    print(dp[n])

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
