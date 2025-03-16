import sys

# Function to read the next integer from the input
def get_next_int():
    return int(sys.stdin.readline().strip())

# Main function to read input and process it
def main():
    # Read the number of test cases from the input
    n = get_next_int()

    # Initialize a list to store the prefix sum of squares of elements
    mm = [0] * (n + 1)

    # Initialize a 2D list to store the dynamic programming table
    dp = [[0] * (n + 1) for _ in range(n + 1)]

    # Read the elements and their prefix sum of squares from the input
    for i in range(n):
        # Read the next integer as the current element
        mm[i + 1] = get_next_int()
        # Read the next integer as the next element's prefix sum of square
        mm[i + 1] += mm[i] * mm[i]

    # Process the dynamic programming table for all subarrays of given size
    for l in range(2, n + 1):
        for i in range(1, n - l + 2):
            j = i + l - 1
            # Iterate through all subarrays of the current subarray
            for k in range(i, j):
                # Calculate the sum of squares of elements in the current subarray
                d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j]
                # Update the dynamic programming table if a larger sum is found
                if dp[i][j] == 0 or dp[i][j] > d:
                    dp[i][j] = d

    # Print the result for the given input
    print(dp[1][n])

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
